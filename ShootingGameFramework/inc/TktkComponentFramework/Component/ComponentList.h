#pragma once

#include <memory>
#include <forward_list>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>
#include <TktkClassFuncProcessor/ClassFuncProcessor.h>
#include "ComponentMetaFunc/ComponentDrawPriorityGetter.h"
#include "ComponentMetaFunc/ComponentCollisionGroupGetter.h"
#include "ComponentFuncableList/MessageableComponentList/MessageableComponentList.h"
#include "ComponentFuncableList/HaveCollisionEnterComponentList/HaveCollisionEnterComponentList.h"
#include "ComponentFuncableList/HaveCollisionStayComponentList/HaveCollisionStayComponentList.h"
#include "ComponentFuncableList/HaveCollisionExitComponentList/HaveCollisionExitComponentList.h"
#include "../GameObject/GameObjectPtr.h"

// コンポーネントを管理するリスト
class ComponentList
{
public:

	ComponentList() = default;

	// 新たなコンポーネントを追加
	template <class T>
	void add(std::shared_ptr<T> component);

	// テンプレートパラメータのコンポーネントを取得
	template <class T>
	std::weak_ptr<T> getComponent() const;

	// 削除されたコンポーネントをリストから外す
	void removeExpandPtr();

	// 全てのコンポーネントを削除する
	void removeAll();

	// 全てのコンポーネントにメッセージを送信する
	void handleMessageAll(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

	// 全てのコンポーネントの衝突開始関数を呼ぶ
	void onCollisionEnterAll(GameObjectPtr other);

	// 全てのコンポーネントの衝突中関数を呼ぶ
	void onCollisionStayAll(GameObjectPtr other);

	// 全てのコンポーネントの衝突終了関数を呼ぶ
	void onCollisionExitAll(GameObjectPtr other);

private:

	std::forward_list<SafetyVoidSmartPtr<std::weak_ptr>> m_componentList;

	MessageableComponentList m_messageableList;

	HaveCollisionEnterComponentList m_haveCollisionEnterComponentList;
	HaveCollisionStayComponentList m_haveCollisionStayComponentList;
	HaveCollisionExitComponentList m_haveCollisionExitComponentList;
};

template<class T>
inline void ComponentList::add(std::shared_ptr<T> component)
{
	float drawPriority = ComponentDrawPriorityGetter::checkToGet(component);
	int collisionGroupType = ComponentCollisionGroupGetter::checkToGet(component);

	ClassFuncProcessor::addClass(drawPriority, collisionGroupType, component);

	std::weak_ptr<T> weakPtr = component;
	m_componentList.push_front(SafetyVoidSmartPtr<std::weak_ptr>(weakPtr));
	m_messageableList.add(weakPtr);

	m_haveCollisionEnterComponentList.checkAndAdd(weakPtr);
	m_haveCollisionStayComponentList.checkAndAdd(weakPtr);
	m_haveCollisionExitComponentList.checkAndAdd(weakPtr);
}

template<class T>
inline std::weak_ptr<T> ComponentList::getComponent() const
{
	for (auto component : m_componentList)
	{
		if (component.canCast<T>()) return component.castPtr<T>();
	}
	return std::weak_ptr<T>();
}

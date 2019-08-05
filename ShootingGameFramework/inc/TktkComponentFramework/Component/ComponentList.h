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

// �R���|�[�l���g���Ǘ����郊�X�g
class ComponentList
{
public:

	ComponentList() = default;

	// �V���ȃR���|�[�l���g��ǉ�
	template <class T>
	void add(std::shared_ptr<T> component);

	// �e���v���[�g�p�����[�^�̃R���|�[�l���g���擾
	template <class T>
	std::weak_ptr<T> getComponent() const;

	// �폜���ꂽ�R���|�[�l���g�����X�g����O��
	void removeExpandPtr();

	// �S�ẴR���|�[�l���g���폜����
	void removeAll();

	// �S�ẴR���|�[�l���g�Ƀ��b�Z�[�W�𑗐M����
	void handleMessageAll(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

	// �S�ẴR���|�[�l���g�̏ՓˊJ�n�֐����Ă�
	void onCollisionEnterAll(GameObjectPtr other);

	// �S�ẴR���|�[�l���g�̏Փ˒��֐����Ă�
	void onCollisionStayAll(GameObjectPtr other);

	// �S�ẴR���|�[�l���g�̏ՓˏI���֐����Ă�
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

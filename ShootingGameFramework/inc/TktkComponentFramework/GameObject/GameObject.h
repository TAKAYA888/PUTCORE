#pragma once

#include <memory>
#include <forward_list>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>
#include "../Component/ComponentList.h"
#include "../Component/ComponentMetaFunc/ComponentUserSetter.h"
#include "GameObjectPtr.h"

// ゲームオブジェクトクラス
class GameObject
	: public std::enable_shared_from_this<GameObject>
{
public:

	// ゲームオブジェクトを生成する
	static GameObjectPtr create();

public:

	GameObject();
	virtual ~GameObject();

	// 親子関係関数
public:

	// 親要素を取得
	GameObjectPtr getParent() const;

	// 親要素を設定
	void setParent(GameObjectPtr parent);

	// 子要素のリストを取得
	std::forward_list<GameObjectPtr> getChildren() const;

	// 子要素をリストに追加する
	void addChild(GameObjectPtr child);

	// 指定した子要素をリストから削除する
	void removeChild(GameObjectPtr child);

	// 全ての子要素にメッセージを送信する
	void sendMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param = std::weak_ptr<void>());

	// コンポーネント関連関数
public:

	// テンプレートパラメータのコンポーネントを取得する
	template <class T>
	std::weak_ptr<T> getComponent() const;

	// コンポーネントを追加する
	template <class T>
	void addComponent(std::shared_ptr<T> component);

	// 全てのコンポーネントの衝突開始関数を呼ぶ
	void runOnCollisionEnterAll(GameObjectPtr other);

	// 全てのコンポーネントの衝突中関数を呼ぶ
	void runOnCollisionStayAll(GameObjectPtr other);

	// 全てのコンポーネントの衝突終了関数を呼ぶ
	void runOnCollisionExitAll(GameObjectPtr other);

	// その他パラメータ設定/取得関数
public:

	// 自身のタグを取得
	int getTag() const;

	// 削除フラグを取得
	bool isDestroy() const;

	// アクティブフラグを取得
	bool isActive() const;
	
	// 自身のタグを設定
	void setTag(int tag);

	// 自身を削除する
	void destroy();

	// アクティブフラグを設定する
	void setActive(bool isActive);

	// ポリモーフィズムな関数
public:

	void awake();

	void update();

	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

	void onDestroy();

private:

	int m_tag{ 0 };
	bool m_isDestroy{ false };
	bool m_isActive{ true };

	ComponentList m_componentList;
};

template<class T>
inline std::weak_ptr<T> GameObject::getComponent() const
{
	return m_componentList.getComponent<T>();
}

template<class T>
inline void GameObject::addComponent(std::shared_ptr<T> component)
{
	m_componentList.add(component);
	ComponentUserSetter::checkToSet(component, weak_from_this());
}

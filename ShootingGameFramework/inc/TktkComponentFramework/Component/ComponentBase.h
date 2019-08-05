#pragma once

#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>
#include "../GameObject/GameObjectPtr.h"
#include "../GameObject/GameObject.h"

/* 
コンポーネントの基底クラス
<PolymorphismFunc>

void awake();
void start();
void onEnable();
void onDisable();
void onDestroy();

void update();
void onCollisionEnter(GameObjectPtr other);
void onCollisionStay(GameObjectPtr other);
void onCollisionExit(GameObjectPtr other);
void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);
*/
class ComponentBase
	: public std::enable_shared_from_this<ComponentBase>
{
public:

	ComponentBase(
		float drawPriority = 0.0f,	// 描画するレイヤー
		int collisionGroupType = 0	// 衝突判定のグループ
	);

	virtual ~ComponentBase();

public:

	// 削除フラグの取得
	bool isDestroy() const;

	// アクティブフラグの取得
	bool isActive() const;

	// 削除する
	void destroy();

	// アクティブフラグを設定
	void setActive(bool isActive);

	// 描画するレイヤーを取得
	float getDrawPriority() const;

	// 衝突判定のグループを取得
	int getCollisionGroupType() const;

	// GameObjectを取得
	GameObjectPtr getGameObject() const;

	// 自身の所持者となるGameObjectを再設定（非推奨）
	void setGameObject(GameObjectPtr user);

public:

	// テンプレートパラメータのコンポーネントを取得する
	template <class T>
	std::weak_ptr<T> getComponent() const;

private:

	bool m_isDestroy{ false };
	bool m_isActive{ true };

	GameObjectPtr m_user;

	float m_drawPriority{ 0.0f };

	int m_collisionGroupType { 0 };
};

template<class T>
inline std::weak_ptr<T> ComponentBase::getComponent() const
{
	return getGameObject().lock()->getComponent<T>();
}
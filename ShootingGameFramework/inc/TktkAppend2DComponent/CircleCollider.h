#pragma once

#include <forward_list>
#include <TktkMath/Vector2.h>
#include <Tktk2dCollision/Body2dBase/Body2dBase.h>
#include <Tktk2dCollision/BoundingCircle.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include "TktkAppend2DComponent/Transform2D.h"

// 真円の当たり判定のコンポーネント
// 【前提コンポーネント：Transform2D】
class CircleCollider
	: public ComponentBase
{
public:

	// std::shared_ptr<CircleCollider>を生成する
	static std::shared_ptr<CircleCollider> create(
		int collisionGroupType,							// 当たり判定のグループ番号
		float radius,									// 当たり判定の半径
		const Vector2& localPosition = Vector2::zero	// 当たり判定のローカル座標
	);

public:

	CircleCollider(
		int collisionGroupType,							// 当たり判定のグループ番号
		float radius,									// 当たり判定の半径
		const Vector2& localPosition = Vector2::zero	// 当たり判定のローカル座標
	);

public:

	// <PolymorphismFunc>
	void update();
	bool isCollide(const SafetyVoidSmartPtr<std::weak_ptr> other);
	void onCollide(SafetyVoidSmartPtr<std::weak_ptr> other);
	void afterCollide();

public:

	// 当たり判定のクラスを取得
	const Body2dBase& getBodyBase() const;

private:

	std::forward_list<GameObjectPtr> m_curHitObjectList;
	std::forward_list<GameObjectPtr> m_preHitObjectList;

	bool m_curIsCollide{ false };
	bool m_preIsCollide{ false };

	HitInfo2D m_hitInfo;

	BoundingCircle m_boundingCircle;

	std::weak_ptr<Transform2D> m_transform2D;
};
#pragma once

#include <forward_list>
#include <TktkMath/Vector2.h>
#include <Tktk2dCollision/Body2dBase/Body2dBase.h>
#include <Tktk2dCollision/BoundingPolygon2d.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include "TktkAppend2DComponent/Transform2D.h"

// 長方形の当たり判定のコンポーネント
// 【前提コンポーネント：Transform2D】
class RectCollider
	: public ComponentBase
{
public:

	// std::shared_ptr<RectCollider>を生成する
	static std::shared_ptr<RectCollider> create(
		int collisionGroupType,							// 当たり判定のグループ番号
		const Vector2& rectSize,						// 当たり判定の大きさ
		const Vector2& localPosition = Vector2::zero	// 当たり判定のローカル座標
	);

public:

	RectCollider(
		int collisionGroupType,							// 当たり判定のグループ番号
		const Vector2& rectSize,						// 当たり判定の大きさ
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

	HitInfo2D m_hitInfo;

	BoundingPolygon2d m_boundingPolygon2d;

	std::weak_ptr<Transform2D> m_transform2D;
};
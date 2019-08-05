#pragma once

#include <TktkMath/Vector2.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include "TktkAppend2DComponent/Transform2D.h"

// ２次元の慣性移動コンポーネント
// 【前提コンポーネント：Transform2D】
class InertialMovement2D
	: public ComponentBase
{
public:

	// std::shared_ptr<InertialMovement2D>を生成する
	static std::shared_ptr<InertialMovement2D> create(
		float dragRate = 3.0f,							// 速度の減衰率（数値が大きければ抵抗が大きくなる）
		const Vector2 & initVelocity = Vector2::zero	// 初期速度
	);

public:

	InertialMovement2D(
		float dragRate = 3.0f,							// 速度の減衰率（数値が大きければ抵抗が大きくなる）
		const Vector2 & initVelocity = Vector2::zero	// 初期速度
	);

public:

	// <PolymorphismFunc>
	void update();

public:

	// 速度上限無しの移動
	void addForce(const Vector2& force);

	// 速度上限を設けての移動
	// ※速度上限を超えた移動をしようとした場合は速度上限値に合わされる
	void addForce(const Vector2& force, float limitSpeed);

	// 現在の速度を取得
	const Vector2& getVelocity() const;

	// 現在の速度を設定
	void setVelocity(const Vector2& velocity);

private:

	std::weak_ptr<Transform2D> m_transform2D;

	Vector2 m_velocity;

	// 毎フレームどれだけの値で速度低下するか
	float m_dragRate;
};
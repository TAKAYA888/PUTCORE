#pragma once

#include <TktkComponentFramework/Component/ComponentBase.h>
#include "TktkAppend2DComponent/Transform2D.h"

// ２次元の慣性回転コンポーネント
// 【前提コンポーネント：Transform2D】
class InertialRotatement2D
	: public ComponentBase
{
public:

	// std::shared_ptr<InertialRotatement2D>を生成する
	static std::shared_ptr<InertialRotatement2D> create(
		float dragRate = 3.0f,		// 回転速度の減衰率（数値が大きければ抵抗が大きくなる）
		float initVelocity = 0.0f	// 初期回転速度
	);

public:

	InertialRotatement2D(
		float dragRate = 3.0f,		// 回転速度の減衰率（数値が大きければ抵抗が大きくなる）
		float initVelocity = 0.0f	// 初期回転速度
	);

public:

	// <PolymorphismFunc>
	void update();

public:

	// 速度上限無しの移動
	void addForce(float force);

	// 速度上限を設けての移動
	// ※速度上限を超えた移動をしようとした場合は速度上限値に合わされる
	void addForce(float force, float limitSpeed);

	// 現在の回転速度を取得
	float getVelocity() const;

	// 現在の回転速度を設定
	void setVelocity(float velocity);

private:

	std::weak_ptr<Transform2D> m_transform2D;

	float m_velocity;

	// 毎フレームどれだけの割合で速度低下するか
	float m_dragRate;
};
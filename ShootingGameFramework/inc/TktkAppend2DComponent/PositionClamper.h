#pragma once

#include <TktkMath/Vector2.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include "TktkAppend2DComponent/Transform2D.h"
#include "TktkAppend2DComponent/InertialMovement2D.h"

// 自身の座標を指定した範囲内にクランプするコンポーネント
// 【前提コンポーネント：Transform2D】
class PositionClamper
	: public ComponentBase
{
public:

	// std::shared_ptr<PositionClamper>を生成する
	static std::shared_ptr<PositionClamper> create(
		const Vector2 & posMin,		// 最小座標
		const Vector2 & posMax		// 最大座標
	);

public:

	PositionClamper(
		const Vector2 & posMin,		// 最小座標
		const Vector2 & posMax		// 最大座標
	);

public:

	// <PolymorphismFunc>
	void update();

private:

	Vector2 m_posMin;
	Vector2 m_posMax;

	std::weak_ptr<Transform2D> m_transform2D;
	std::weak_ptr<InertialMovement2D> m_inertialMovement2D;
};
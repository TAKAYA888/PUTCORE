#pragma once

#include <TktkMath/Vector2.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include "TktkAppend2DComponent/Transform2D.h"

// 指定した範囲外の座標に移動したら自身を削除するコンポーネント
// 【前提コンポーネント：Transform2D】
class OutScreenSelfDestroyer2D
	: public ComponentBase
{
public:

	// std::shared_ptr<OutScreenSelfDestroyer2D>を生成する
	static std::shared_ptr<OutScreenSelfDestroyer2D> create(
		const Vector2 & posMin,	// 最小座標
		const Vector2 & posMax	// 最大座標
	);

public:

	OutScreenSelfDestroyer2D(
		const Vector2 & posMin,	// 最小座標
		const Vector2 & posMax	// 最大座標
	);

public:

	// <PolymorphismFunc>
	void update();

private:

	Vector2 m_posMin;
	Vector2 m_posMax;

	std::weak_ptr<Transform2D> m_transform2D;
};
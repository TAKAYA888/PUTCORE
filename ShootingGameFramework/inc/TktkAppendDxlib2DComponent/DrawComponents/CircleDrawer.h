#pragma once

#include <TktkMath/Color.h>
#include <TktkMath/Vector2.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include <TktkAppend2DComponent/Transform2D.h>

// 真円の描画コンポーネント
// 【前提コンポーネント：Transform2D】
class CircleDrawer
	: public ComponentBase
{
public:

	CircleDrawer(
		float drawPriority,	// 描画するレイヤーの種類
		const Color& color,	// 真円の色
		float radius		// 真円の半径
	);

	CircleDrawer(
		float drawPriority,	// 描画するレイヤーの種類
		const Color& color,	// 真円の色
		float radius,		// 真円の半径
		float lineThickness	// 真円の幅
	);

public:

	void update();
	void draw() const;

private:

	std::weak_ptr<Transform2D> m_transform2D;

	Color m_color;

	float m_radius;

	float m_lineThickness{ -1.0f };
};
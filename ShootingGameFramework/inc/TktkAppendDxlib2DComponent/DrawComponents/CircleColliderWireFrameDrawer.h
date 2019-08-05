#pragma once

#include <TktkMath/Color.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include <TktkAppend2DComponent/CircleCollider.h>

// 真円の当たり判定の境界線を描画するコンポーネント
// 【前提コンポーネント：CircleCollider】
class CircleColliderWireFrameDrawer
	: public ComponentBase
{
public:

	CircleColliderWireFrameDrawer(
		float drawPriority,			// 描画するレイヤーの種類
		const Color& wireFrameColor	// 境界線を描画する色
	);

public:

	void update();
	void draw() const;

private:

	std::weak_ptr<CircleCollider> m_circleCollider;

	Color m_wireFrameColor;
};
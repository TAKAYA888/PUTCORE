#pragma once

#include <TktkMath/Color.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include <TktkAppend2DComponent/RectCollider.h>

// 長方形の当たり判定の境界線を描画するコンポーネント
// 【前提コンポーネント：RectCollider】
class RectColliderWireFrameDrawer
	: public ComponentBase
{
public:

	RectColliderWireFrameDrawer(
		float drawPriority,			// 描画するレイヤーの種類
		const Color& wireFrameColor	// 境界線を描画する色
	);

public:

	void update();
	void draw() const;

private:

	std::weak_ptr<RectCollider> m_rectCollider;

	Color m_wireFrameColor;
};
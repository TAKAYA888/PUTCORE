#pragma once

#include <TktkMath/Color.h>
#include <TktkMath/Vector2.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include <TktkAppend2DComponent/Transform2D.h>

// ^~Μ`ζR|[lg
// yOρR|[lgFTransform2Dz
class CircleDrawer
	: public ComponentBase
{
public:

	CircleDrawer(
		float drawPriority,	// `ζ·ιC[Μνή
		const Color& color,	// ^~ΜF
		float radius		// ^~ΜΌa
	);

	CircleDrawer(
		float drawPriority,	// `ζ·ιC[Μνή
		const Color& color,	// ^~ΜF
		float radius,		// ^~ΜΌa
		float lineThickness	// ^~Μ
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
#pragma once

#include <TktkMath/Color.h>
#include <TktkMath/Vector2.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include <TktkAppend2DComponent/Transform2D.h>

// �^�~�̕`��R���|�[�l���g
// �y�O��R���|�[�l���g�FTransform2D�z
class CircleDrawer
	: public ComponentBase
{
public:

	CircleDrawer(
		float drawPriority,	// �`�悷�郌�C���[�̎��
		const Color& color,	// �^�~�̐F
		float radius		// �^�~�̔��a
	);

	CircleDrawer(
		float drawPriority,	// �`�悷�郌�C���[�̎��
		const Color& color,	// �^�~�̐F
		float radius,		// �^�~�̔��a
		float lineThickness	// �^�~�̕�
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
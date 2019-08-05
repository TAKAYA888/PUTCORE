#pragma once

#include <TktkMath/Color.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include <TktkAppend2DComponent/CircleCollider.h>

// �^�~�̓����蔻��̋��E����`�悷��R���|�[�l���g
// �y�O��R���|�[�l���g�FCircleCollider�z
class CircleColliderWireFrameDrawer
	: public ComponentBase
{
public:

	CircleColliderWireFrameDrawer(
		float drawPriority,			// �`�悷�郌�C���[�̎��
		const Color& wireFrameColor	// ���E����`�悷��F
	);

public:

	void update();
	void draw() const;

private:

	std::weak_ptr<CircleCollider> m_circleCollider;

	Color m_wireFrameColor;
};
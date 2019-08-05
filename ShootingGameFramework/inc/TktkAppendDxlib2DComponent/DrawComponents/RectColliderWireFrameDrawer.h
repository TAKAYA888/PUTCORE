#pragma once

#include <TktkMath/Color.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include <TktkAppend2DComponent/RectCollider.h>

// �����`�̓����蔻��̋��E����`�悷��R���|�[�l���g
// �y�O��R���|�[�l���g�FRectCollider�z
class RectColliderWireFrameDrawer
	: public ComponentBase
{
public:

	RectColliderWireFrameDrawer(
		float drawPriority,			// �`�悷�郌�C���[�̎��
		const Color& wireFrameColor	// ���E����`�悷��F
	);

public:

	void update();
	void draw() const;

private:

	std::weak_ptr<RectCollider> m_rectCollider;

	Color m_wireFrameColor;
};
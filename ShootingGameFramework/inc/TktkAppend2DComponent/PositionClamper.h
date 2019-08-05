#pragma once

#include <TktkMath/Vector2.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include "TktkAppend2DComponent/Transform2D.h"
#include "TktkAppend2DComponent/InertialMovement2D.h"

// ���g�̍��W���w�肵���͈͓��ɃN�����v����R���|�[�l���g
// �y�O��R���|�[�l���g�FTransform2D�z
class PositionClamper
	: public ComponentBase
{
public:

	// std::shared_ptr<PositionClamper>�𐶐�����
	static std::shared_ptr<PositionClamper> create(
		const Vector2 & posMin,		// �ŏ����W
		const Vector2 & posMax		// �ő���W
	);

public:

	PositionClamper(
		const Vector2 & posMin,		// �ŏ����W
		const Vector2 & posMax		// �ő���W
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
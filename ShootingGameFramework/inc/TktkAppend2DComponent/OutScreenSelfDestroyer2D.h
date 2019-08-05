#pragma once

#include <TktkMath/Vector2.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include "TktkAppend2DComponent/Transform2D.h"

// �w�肵���͈͊O�̍��W�Ɉړ������玩�g���폜����R���|�[�l���g
// �y�O��R���|�[�l���g�FTransform2D�z
class OutScreenSelfDestroyer2D
	: public ComponentBase
{
public:

	// std::shared_ptr<OutScreenSelfDestroyer2D>�𐶐�����
	static std::shared_ptr<OutScreenSelfDestroyer2D> create(
		const Vector2 & posMin,	// �ŏ����W
		const Vector2 & posMax	// �ő���W
	);

public:

	OutScreenSelfDestroyer2D(
		const Vector2 & posMin,	// �ŏ����W
		const Vector2 & posMax	// �ő���W
	);

public:

	// <PolymorphismFunc>
	void update();

private:

	Vector2 m_posMin;
	Vector2 m_posMax;

	std::weak_ptr<Transform2D> m_transform2D;
};
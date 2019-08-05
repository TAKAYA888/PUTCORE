#pragma once

#include <TktkComponentFramework/Component/ComponentBase.h>
#include "TktkAppend2DComponent/Transform2D.h"

// �Q�����̊�����]�R���|�[�l���g
// �y�O��R���|�[�l���g�FTransform2D�z
class InertialRotatement2D
	: public ComponentBase
{
public:

	// std::shared_ptr<InertialRotatement2D>�𐶐�����
	static std::shared_ptr<InertialRotatement2D> create(
		float dragRate = 3.0f,		// ��]���x�̌������i���l���傫����Β�R���傫���Ȃ�j
		float initVelocity = 0.0f	// ������]���x
	);

public:

	InertialRotatement2D(
		float dragRate = 3.0f,		// ��]���x�̌������i���l���傫����Β�R���傫���Ȃ�j
		float initVelocity = 0.0f	// ������]���x
	);

public:

	// <PolymorphismFunc>
	void update();

public:

	// ���x��������̈ړ�
	void addForce(float force);

	// ���x�����݂��Ă̈ړ�
	// �����x����𒴂����ړ������悤�Ƃ����ꍇ�͑��x����l�ɍ��킳���
	void addForce(float force, float limitSpeed);

	// ���݂̉�]���x���擾
	float getVelocity() const;

	// ���݂̉�]���x��ݒ�
	void setVelocity(float velocity);

private:

	std::weak_ptr<Transform2D> m_transform2D;

	float m_velocity;

	// ���t���[���ǂꂾ���̊����ő��x�ቺ���邩
	float m_dragRate;
};
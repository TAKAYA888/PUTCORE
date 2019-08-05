#pragma once

#include <TktkMath/Vector2.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include "TktkAppend2DComponent/Transform2D.h"

// �Q�����̊����ړ��R���|�[�l���g
// �y�O��R���|�[�l���g�FTransform2D�z
class InertialMovement2D
	: public ComponentBase
{
public:

	// std::shared_ptr<InertialMovement2D>�𐶐�����
	static std::shared_ptr<InertialMovement2D> create(
		float dragRate = 3.0f,							// ���x�̌������i���l���傫����Β�R���傫���Ȃ�j
		const Vector2 & initVelocity = Vector2::zero	// �������x
	);

public:

	InertialMovement2D(
		float dragRate = 3.0f,							// ���x�̌������i���l���傫����Β�R���傫���Ȃ�j
		const Vector2 & initVelocity = Vector2::zero	// �������x
	);

public:

	// <PolymorphismFunc>
	void update();

public:

	// ���x��������̈ړ�
	void addForce(const Vector2& force);

	// ���x�����݂��Ă̈ړ�
	// �����x����𒴂����ړ������悤�Ƃ����ꍇ�͑��x����l�ɍ��킳���
	void addForce(const Vector2& force, float limitSpeed);

	// ���݂̑��x���擾
	const Vector2& getVelocity() const;

	// ���݂̑��x��ݒ�
	void setVelocity(const Vector2& velocity);

private:

	std::weak_ptr<Transform2D> m_transform2D;

	Vector2 m_velocity;

	// ���t���[���ǂꂾ���̒l�ő��x�ቺ���邩
	float m_dragRate;
};
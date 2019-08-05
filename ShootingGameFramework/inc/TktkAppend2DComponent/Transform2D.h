#ifndef TRANSFORM_2D_H_
#define TRANSFORM_2D_H_

#include <TktkMath/Matrix3.h>
#include <TktkMath/Vector2.h>
#include <TktkComponentFramework/Component/ComponentBase.h>

// ���g�̍��W�A��]�A�X�P�[�����Ǘ�����R���|�[�l���g
class Transform2D
	: public ComponentBase
{
public:

	// �e��Transform2D�Ƃ̊֌W���̎��
	enum TraceParentType
	{
		// �e�̍��W�݂̂��Q�Ƃ���
		TRACE_PARENT_POS					= 1 << 0,

		// �e�̃X�P�[���݂̂��Q�Ƃ���
		TRACE_PARENT_SCALE					= 1 << 1,

		// �e�̉�]�݂̂��Q�Ƃ���
		TRACE_PARENT_ROTATION				= 1 << 2,

		// �e��Transform2D���Q�Ƃ��Ȃ�
		NOT_TRACE_PARENT					= 0,

		// �e�̍��W�ƃX�P�[�����Q�Ƃ���
		TRACE_PARENT_POS_AND_SCALE			= TRACE_PARENT_POS | TRACE_PARENT_SCALE,

		// �e�̍��W�Ɖ�]���Q�Ƃ���
		TRACE_PARENT_POS_AND_ROTATION		= TRACE_PARENT_POS | TRACE_PARENT_ROTATION,

		// �e�̃X�P�[���Ɖ�]���Q�Ƃ���
		TRACE_PARENT_SCALE_AND_ROTATION		= TRACE_PARENT_SCALE | TRACE_PARENT_ROTATION,

		// �e��Transform2D�����S�ɎQ�Ƃ���
		TRACE_PARENT_ALL					= TRACE_PARENT_POS | TRACE_PARENT_SCALE | TRACE_PARENT_ROTATION,
	};

public:

	// std::shared_ptr<Transform2D>�𐶐�����
	static std::shared_ptr<Transform2D> create(
		const Vector2& initPosition,					// �������W
		const Vector2& initScaleRate,					// �����X�P�[��
		float initRotationDeg,							// ������]
		TraceParentType traceType = TRACE_PARENT_ALL	// �e��Transform2D�Ƃ̊֌W���̎��
	);

public:

	Transform2D(
		const Vector2& initPosition,					// �������W
		const Vector2& initScaleRate,					// �����X�P�[��
		float initRotationDeg,							// ������]
		TraceParentType traceType = TRACE_PARENT_ALL	// �e��Transform2D�Ƃ̊֌W���̎��
	);

public:

	// ���[���h�̍s����擾
	const Matrix3& getPose() const;

	// ���[���h���W���擾
	Vector2 getWorldPosition() const;
	// ���[���h�X�P�[�����擾
	Vector2 getWorldScaleRate() const;
	// ���[���h��]���擾
	float getWorldRotationDeg() const;

	// ���[�J�����W���擾
	const Vector2& getLocalPosition() const;
	// ���[�J���X�P�[�����擾
	const Vector2& getLocalScaleRate() const;
	// ���[�J����]���擾
	float getLocalRotationDeg() const;

	// ���[�J�����W��ݒ�
	void setLocalPosition(const Vector2& position);
	// ���[�J���X�P�[����ݒ�
	void setLocalScaleRate(const Vector2& scaleRate);
	// ���[�J����]��ݒ�
	void setLocalRotationDeg(float rotationDeg);

	// �s��̍Čv�Z
	void reCalculateMatrix();

public:

	// <PolymorphismFunc>
	void start();
	void update();
	void afterCollide();

private:

	// �s��v�Z
	void calculateMatrix();

	// �e��Transform2D���擾
	std::weak_ptr<Transform2D> findParentTransform2D(GameObjectPtr parent);

private:

	bool m_preFlameTransformParent{ false };

	Vector2 m_localPosition;
	Vector2 m_localScaleRate;
	float m_localRotationDeg;

	Matrix3 m_localMatrix;
	Matrix3 m_worldMatrix;
	Matrix3 m_parentMatrix;

	TraceParentType m_traceType;
};
#endif // !TRANSFORM_2D_H_
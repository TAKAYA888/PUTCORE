#ifndef QUATERNION_H_
#define QUATERNION_H_

#include <ostream>
#include "TktkMath/Vector3.h"

struct Matrix4;

struct Quaternion
{
	float x, y, z, w;

	Quaternion(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f);

	Quaternion(const Vector3& axis, float degree);

	float operator[](int index) const;
	float& operator[](int index);

	void set(float x, float y, float z, float w);

	// �t�H�[�}�b�g���ꂽ������ɕϊ�
	std::string toString() const;

	// ���K������
	Quaternion normalized() const;

	// �m���������߂�
	float length() const;

	// �I�C���[�p�����߂�
	Vector3 eulerAngles() const;

	// �I�C���[�p����N�I�[�^�j�I�����쐬
	void eulerAngles(const Vector3& value);

	// from->to�̉�]�����߂�
	void setFromToRotation(const Vector3& fromDirection, const Vector3& toDirection);

	// �w�肵����������������]�����߂�
	void setLookRotation(const Vector3& view, const Vector3& up = Vector3::up);

	// �Q�̉�]����̓�����������^��Ԃ�
	bool equals(const Quaternion& other) const;

	// �I�C���[�p����N�I�[�^�j�I�����쐬
	static Quaternion euler(float x, float y, float z);
	static Quaternion euler(const Vector3& value);

	// from->to�̉�]�����߂�
	static Quaternion fromToRotation(const Vector3& fromDirection, const Vector3& toDirection);

	// �w�肵����������������]�����߂�
	static Quaternion lookRotation(const Vector3& view, const Vector3& up = Vector3::up);

	// from->to�ւ̉�]�����߂�
	static Quaternion rotateTowards(const Quaternion& from, const Quaternion& to, float maxDegreesDelta);

	// a��b�̊Ԃ�t�Ő��`��Ԃ���it��0��1�̊ԂŃN�����v����j
	static Quaternion lerp(const Quaternion& value1, const Quaternion& value2, float t);

	// a��b�̊Ԃ�t�Ő��`��Ԃ���
	static Quaternion lerpUnclamped(const Quaternion& value1, const Quaternion& value2, float t);

	// �Q�̉�] a �� b �Ԃ̊p�x��Ԃ�
	static float angle(const Quaternion& q1, const Quaternion& q2);

	// axis�̎���� degree �x������]����N�I�[�^�j�I�����쐬
	static Quaternion angleAxis(const Vector3& axis, float degree);

	// ���ς����߂�
	static float dot(const Quaternion& q1, const Quaternion& q2);

	// ��]�s�񂩂�N�I�[�^�j�I�����쐬
	static Quaternion createFromRotationMatrix(const Matrix4& matrix);

	// �t�N�I�[�^�j�I����Ԃ��܂�
	static Quaternion inverse(Quaternion& rotation);

	// ���K������
	static Quaternion normalize(const Quaternion& q);

	// ���ʐ��`���
	static Quaternion slerp(const Quaternion& value1, const Quaternion& value2, float amount);

	// ���ʐ��`���
	// ��������
	static Quaternion slerpUnclamped(const Quaternion& value1, const Quaternion& value2, float amount);

	// �P�ʃN�I�[�^�j�I��
	static const Quaternion identity;
};

Quaternion operator - (const Quaternion& q);

Quaternion& operator += (Quaternion& q1, const Quaternion& q2);
Quaternion& operator -= (Quaternion& q1, const Quaternion& q2);
Quaternion& operator *= (Quaternion& q, float s);
Quaternion& operator /= (Quaternion& q, float s);
Quaternion& operator *= (Quaternion& q1, const Quaternion& q2);

Quaternion operator + (Quaternion q1, const Quaternion& q2);
Quaternion operator - (Quaternion q1, const Quaternion& q2);
Quaternion operator * (Quaternion q1, const Quaternion& q2);
Quaternion operator * (Quaternion q, float s);
Quaternion operator * (float s, Quaternion q);
Quaternion operator / (Quaternion q, float s);

Vector3 operator * (const Quaternion& rotation, const Vector3& point);

std::ostream& operator<<(std::ostream& os, const Quaternion& quaternion);

#endif
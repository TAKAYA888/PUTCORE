#ifndef MATRIX4_H_
#define MATRIX4_H_

#include <ostream>

struct Vector3;
struct Quaternion;

struct Matrix4
{
	float m[4][4];

	Matrix4(
		float m11 = 1.0f, float m12 = 0.0f, float m13 = 0.0f, float m14 = 0.0f,
		float m21 = 0.0f, float m22 = 1.0f, float m23 = 0.0f, float m24 = 0.0f,
		float m31 = 0.0f, float m32 = 0.0f, float m33 = 1.0f, float m34 = 0.0f,
		float m41 = 0.0f, float m42 = 0.0f, float m43 = 0.0f, float m44 = 1.0f);

	// �t�H�[�}�b�g���ꂽ������ɕϊ�
	std::string toString() const;

	// �X�P�[���s����쐬
	static Matrix4 createScale(const Vector3& scale);

	// �ړ��s����쐬
	static Matrix4 createTranslation(const Vector3& translation);

	// �C�ӂ̎��̉�]�s��𐶐�
	static Matrix4 createFromAxisAngle(const Vector3& axis, float degree);

	// �N�I�[�^�j�I�������]�s��𐶐�
	// �ustatic Matrix4 rotate(const Quaternion& q);�v�Ɠ����ł�
	static Matrix4 createFromQuaternion(const Quaternion& rotate);

	// ���[�A�s�b�`�A���[���ŉ�]�s��𐶐�
	static Matrix4 createFromYawPitchRoll(float yaw, float pitch, float roll);

	// x���̉�]�s��𐶐�
	static Matrix4 createRotationX(float degree);

	// y���̉�]�s��𐶐�
	static Matrix4 createRotationY(float degree);

	// z���̉�]�s��𐶐�
	static Matrix4 createRotationZ(float degree);

	// ���[���h�s��𐶐�
	static Matrix4 createWorld(const Vector3& scale, const Quaternion& rotation, const Vector3& translation);

	// ���[���h�s��𐶐�
	static Matrix4 createWorld(const Vector3& scale, const Matrix4& rotation, const Vector3& translation);

	// ������W�n�̃��[���h�s��𐶐��iDirectX���j
	static Matrix4 createWorldLH(const Vector3& position, const Vector3& forward, const Vector3& up);

	// �E����W�n�̃��[���h�s��𐶐��iOpenGL���j
	static Matrix4 createWorldRH(const Vector3& position, const Vector3& forward, const Vector3& up);

	// ������W�n�̃p�[�X�y�N�e�B�u�ˉe�s��𐶐��iDirectX���j
	static Matrix4 createPerspectiveFieldOfViewLH(float fov, float aspect, float near, float far);

	// �E����W�n�̃p�[�X�y�N�e�B�u�ˉe�s��𐶐��iOpenGL���j
	static Matrix4 createPerspectiveFieldOfViewRH(float fov, float aspect, float near, float far);

	// ������W�n�̃r���[�s��𐶐��iDirectX���j
	static Matrix4 createLookAtLH(const Vector3& position, const Vector3& target, const Vector3& up);

	// �E����W�n�̃r���[�s��𐶐��iOpenGL���j
	static Matrix4 createLookAtRH(const Vector3& position, const Vector3& target, const Vector3& up);

	// �X�N���[�����W�n�ɕϊ�����s��𐶐�
	static Matrix4 createScreen(float x, float y, float width, float height);

	// �t�s��𐶐�
	static Matrix4 invert(const Matrix4& matrix);

	// �t�s��𐶐��i��]�ƕ��s�ړ��̂݁j
	static Matrix4 invertFast(const Matrix4& matrix);

	// �s��̍s�Ɨ�����ւ��܂��B
	static Matrix4 transpose(const Matrix4& matrix);

	// 2�̍s��̑Ή�����l�̊Ԃ���`��Ԃ��܂�
	static Matrix4 lerp(const Matrix4& value1, const Matrix4& value2, float amount);

	// 3D �X�P�[�� / ��] / �ϊ�(SRT) Matrix ����X�J���[�A�ϊ��A��]�̃R���|�[�l���g���擾���܂�
	void decompose(Vector3& scale, Quaternion& rotation, Vector3& translation) const;

	// ��]�s��𐳋K�����܂��B
	static Matrix4 normalizeRotationMatrix(const Matrix4& matrix);

	// ��]�s��𐳋K�����܂��B
	Matrix4& normalizeRotationMatrix();

	// ������W�n�̑O���x�N�g�����擾�iDirectX���j
	Vector3 forwardLH() const;

	// �E����W�n�̑O���x�N�g�����擾�iOpenGL���j
	Vector3 forwardRH() const;

	// ������W�n�̑O���x�N�g����ݒ�iDirectX���j
	Matrix4& forwardLH(const Vector3& forward);

	// �E����W�n�̑O���x�N�g����ݒ�iOpenGL���j
	Matrix4& forwardRH(const Vector3& forward);

	// ������W�n�̌���x�N�g�����擾�iDirectX���j
	Vector3 backwardLH() const;

	// �E����W�n�̌���x�N�g�����擾�iOpenGL���j
	Vector3 backwardRH() const;

	// ������W�n�̌���x�N�g����ݒ�iDirectX���j
	Matrix4& backwardLH(const Vector3& bakward);

	// �E����W�n�̌���x�N�g����ݒ�iOpenGL���j
	Matrix4& backwardRH(const Vector3& bakward);

	// ����x�N�g�����擾
	Vector3 up() const;

	// ����x�N�g����ݒ�
	Matrix4& up(const Vector3& up);

	// �����x�N�g�����擾
	Vector3 down() const;

	// �����x�N�g����ݒ�
	Matrix4& down(const Vector3& down);

	// ���x�N�g�����擾
	Vector3 left() const;

	// ���x�N�g����ݒ�
	Matrix4& left(const Vector3& left);

	// �E�x�N�g�����擾
	Vector3 right() const;

	// �E�x�N�g����ݒ�
	Matrix4& right(const Vector3& rignt);

	// ���s�ړ��x�N�g�����擾
	Vector3 translation() const;

	// ���s�ړ��x�N�g����ݒ�
	Matrix4& translation(const Vector3& translation);

	// �X�P�[���l���擾
	Vector3 scale() const;

	// ��]�̎擾
	Quaternion rotation() const;

	// ��]�s��̎擾
	Matrix4 rotationMatrix() const;

	// �t�s����擾
	Matrix4 inverse() const;

	// �]�u�s��̎擾
	Matrix4 transpose() const;

	// �ړ���]�X�P�[�����O�̐ݒ���s��
	void setTRS(const Vector3& t, const Quaternion& r, const Vector3& s);

	// �P�ʍs��
	static const Matrix4 identity;

	// �[���s��
	static const Matrix4 zero;
};

Matrix4 operator - (const Matrix4& v);

Matrix4& operator += (Matrix4& m1, const Matrix4& m2);
Matrix4& operator -= (Matrix4& m1, const Matrix4& m2);
Matrix4& operator *= (Matrix4& m1, const Matrix4& m2);
Matrix4& operator *= (Matrix4& m, float s);
Matrix4& operator /= (Matrix4& m, float s);

Matrix4  operator * (Matrix4 m1, const Matrix4& m2);
Matrix4  operator * (Matrix4 m, float s);
Matrix4  operator * (Matrix4 s, float m);
Vector3 operator * (const Vector3& v, const Matrix4& m);

Matrix4 operator + (Matrix4 m1, const Matrix4& m2);
Matrix4 operator - (Matrix4 m1, const Matrix4& m2);
Matrix4 operator * (Matrix4 m, float s);
Matrix4 operator * (float s, Matrix4 m);
Matrix4 operator / (Matrix4 m, float s);

std::ostream& operator<<(std::ostream& os, const Matrix4& matrix);

#endif
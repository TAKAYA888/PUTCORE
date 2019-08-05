#ifndef MATRIX3_H_
#define MATRIX3_H_

#include <ostream>

struct Vector2;

struct Matrix3
{
	float m[3][3];

	Matrix3(
		float m11 = 1.0f, float m12 = 0.0f, float m13 = 0.0f,
		float m21 = 0.0f, float m22 = 1.0f, float m23 = 0.0f,
		float m31 = 0.0f, float m32 = 0.0f, float m33 = 1.0f);

	// �t�H�[�}�b�g���ꂽ������ɕϊ�
	std::string toString() const;

	// �X�P�[���s����쐬
	static Matrix3 createScale(const Vector2& scale);

	// �ړ��s����쐬
	static Matrix3 createTranslation(const Vector2& translation);

	// ��]�s��𐶐�
	static Matrix3 createRotation(float degree);

	// ���[���h�s��𐶐�
	static Matrix3 createWorld(const Vector2& translation, const Vector2& scale, float rotationDeg);

	// �t�s��𐶐�
	// ��������
	static Matrix3 invert(const Matrix3& matrix);

	// �t�s��𐶐��i��]�ƕ��s�ړ��̂݁j
	// ��������
	static Matrix3 invertFast(const Matrix3& matrix);

	// �s��̍s�Ɨ�����ւ��܂��B
	static Matrix3 transpose(const Matrix3& matrix);

	// ����x�N�g�����擾
	Vector2 up() const;

	// ����x�N�g����ݒ�
	Matrix3& up(const Vector2& up);

	// �����x�N�g�����擾
	Vector2 down() const;

	// �����x�N�g����ݒ�
	Matrix3& down(const Vector2& down);

	// ���x�N�g�����擾
	Vector2 left() const;

	// ���x�N�g����ݒ�
	Matrix3& left(const Vector2& left);

	// �E�x�N�g�����擾
	Vector2 right() const;

	// �E�x�N�g����ݒ�
	Matrix3& right(const Vector2& rignt);


	// 2�̍s��̑Ή�����l�̊Ԃ���`��Ԃ��܂�
	//static Matrix3 lerp(const Matrix3& value1, const Matrix3& value2, float amount);

	// ���s�ړ��x�N�g�����擾
	Vector2 translation() const;

	// ���s�ړ��x�N�g����ݒ�
	Matrix3& translation(const Vector2& translation);

	// �X�P�[���l���擾
	Vector2 scale() const;

	// ��]�̎擾
	float rotationDeg() const;

	// �P�ʍs��
	static const Matrix3 identity;

	// �[���s��
	static const Matrix3 zero;
};

Matrix3 operator - (const Matrix3& m);

Matrix3& operator += (Matrix3& m1, const Matrix3& m2);
Matrix3& operator -= (Matrix3& m1, const Matrix3& m2);
Matrix3& operator *= (Matrix3& m1, const Matrix3& m2);
Matrix3& operator *= (Matrix3& m, float s);
Matrix3& operator /= (Matrix3& m, float s);

Matrix3 operator + (Matrix3 m1, const Matrix3& m2);
Matrix3 operator - (Matrix3 m1, const Matrix3& m2);
Matrix3 operator * (Matrix3 m1, const Matrix3& m2);
Matrix3 operator * (Matrix3 m, float s);
Matrix3 operator * (float s, Matrix3 m);
Matrix3 operator / (Matrix3 m, float s);

std::ostream& operator<<(std::ostream& os, const Matrix3& matrix);

#endif
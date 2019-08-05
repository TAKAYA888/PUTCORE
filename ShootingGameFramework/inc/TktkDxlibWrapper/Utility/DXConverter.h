#ifndef DX_CONVERTER_H_
#define DX_CONVERTER_H_

#include <DxLib.h>

#include <TktkMath/Vector3.h>
#include <TktkMath/Color.h>
#include <TktkMath/Matrix4.h>

// �l�X�ȍ\���̂�Dxlib��ɕϊ�����
class DXConverter
{
public:

	// Vector3��VECTOR�ɕϊ����ĕԂ�
	static VECTOR toVECTOR(const Vector3& v);

	// VECTOR��Vector3�ɕϊ����ĕԂ�
	static Vector3 toVector3(const VECTOR& v);

	// Color��unsigned int�ɕϊ����ĕԂ��iDxlib��GetColor()���Ăԁj
	static unsigned int toUintColor(const Color& color);

	// Color��COLOR_F�ɕϊ����ĕԂ�
	static COLOR_F toCOLOR_F(const Color& color);

	// COLOR_F��Color�ɕϊ����ĕԂ�
	static Color toColor(const COLOR_F& color_f);

	// Matrix4��MATRIX�ɕϊ����ĕԂ�
	static MATRIX toMATRIX(const Matrix4& m);

	// Matrix4��MATRIX_D�ɕϊ����ĕԂ�
	static MATRIX_D toMATRIX_D(const Matrix4& m);

	// MATRIX��Matrix4�ɕϊ����ĕԂ�
	static Matrix4 toMatrix(const MATRIX& m);
};

#endif // ! DX_CONVERTER_H_


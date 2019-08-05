#ifndef DX_CONVERTER_H_
#define DX_CONVERTER_H_

#include <DxLib.h>

#include <TktkMath/Vector3.h>
#include <TktkMath/Color.h>
#include <TktkMath/Matrix4.h>

// 様々な構造体をDxlib基準に変換する
class DXConverter
{
public:

	// Vector3→VECTORに変換して返す
	static VECTOR toVECTOR(const Vector3& v);

	// VECTOR→Vector3に変換して返す
	static Vector3 toVector3(const VECTOR& v);

	// Color→unsigned intに変換して返す（DxlibのGetColor()を呼ぶ）
	static unsigned int toUintColor(const Color& color);

	// Color→COLOR_Fに変換して返す
	static COLOR_F toCOLOR_F(const Color& color);

	// COLOR_F→Colorに変換して返す
	static Color toColor(const COLOR_F& color_f);

	// Matrix4→MATRIXに変換して返す
	static MATRIX toMATRIX(const Matrix4& m);

	// Matrix4→MATRIX_Dに変換して返す
	static MATRIX_D toMATRIX_D(const Matrix4& m);

	// MATRIX→Matrix4に変換して返す
	static Matrix4 toMatrix(const MATRIX& m);
};

#endif // ! DX_CONVERTER_H_


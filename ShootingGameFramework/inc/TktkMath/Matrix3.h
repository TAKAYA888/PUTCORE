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

	// フォーマットされた文字列に変換
	std::string toString() const;

	// スケール行列を作成
	static Matrix3 createScale(const Vector2& scale);

	// 移動行列を作成
	static Matrix3 createTranslation(const Vector2& translation);

	// 回転行列を生成
	static Matrix3 createRotation(float degree);

	// ワールド行列を生成
	static Matrix3 createWorld(const Vector2& translation, const Vector2& scale, float rotationDeg);

	// 逆行列を生成
	// ※未実装
	static Matrix3 invert(const Matrix3& matrix);

	// 逆行列を生成（回転と平行移動のみ）
	// ※未実装
	static Matrix3 invertFast(const Matrix3& matrix);

	// 行列の行と列を入れ替えます。
	static Matrix3 transpose(const Matrix3& matrix);

	// 上方ベクトルを取得
	Vector2 up() const;

	// 上方ベクトルを設定
	Matrix3& up(const Vector2& up);

	// 下方ベクトルを取得
	Vector2 down() const;

	// 下方ベクトルを設定
	Matrix3& down(const Vector2& down);

	// 左ベクトルを取得
	Vector2 left() const;

	// 左ベクトルを設定
	Matrix3& left(const Vector2& left);

	// 右ベクトルを取得
	Vector2 right() const;

	// 右ベクトルを設定
	Matrix3& right(const Vector2& rignt);


	// 2つの行列の対応する値の間を線形補間します
	//static Matrix3 lerp(const Matrix3& value1, const Matrix3& value2, float amount);

	// 平行移動ベクトルを取得
	Vector2 translation() const;

	// 平行移動ベクトルを設定
	Matrix3& translation(const Vector2& translation);

	// スケール値を取得
	Vector2 scale() const;

	// 回転の取得
	float rotationDeg() const;

	// 単位行列
	static const Matrix3 identity;

	// ゼロ行列
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
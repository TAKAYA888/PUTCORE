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

	// フォーマットされた文字列に変換
	std::string toString() const;

	// 正規化する
	Quaternion normalized() const;

	// ノルムを求める
	float length() const;

	// オイラー角を求める
	Vector3 eulerAngles() const;

	// オイラー角からクオータニオンを作成
	void eulerAngles(const Vector3& value);

	// from->toの回転を求める
	void setFromToRotation(const Vector3& fromDirection, const Vector3& toDirection);

	// 指定した方向を向いた回転を求める
	void setLookRotation(const Vector3& view, const Vector3& up = Vector3::up);

	// ２つの回転が大体同じだったら真を返す
	bool equals(const Quaternion& other) const;

	// オイラー角からクオータニオンを作成
	static Quaternion euler(float x, float y, float z);
	static Quaternion euler(const Vector3& value);

	// from->toの回転を求める
	static Quaternion fromToRotation(const Vector3& fromDirection, const Vector3& toDirection);

	// 指定した方向を向いた回転を求める
	static Quaternion lookRotation(const Vector3& view, const Vector3& up = Vector3::up);

	// from->toへの回転を求める
	static Quaternion rotateTowards(const Quaternion& from, const Quaternion& to, float maxDegreesDelta);

	// aとbの間をtで線形補間する（tを0と1の間でクランプする）
	static Quaternion lerp(const Quaternion& value1, const Quaternion& value2, float t);

	// aとbの間をtで線形補間する
	static Quaternion lerpUnclamped(const Quaternion& value1, const Quaternion& value2, float t);

	// ２つの回転 a と b 間の角度を返す
	static float angle(const Quaternion& q1, const Quaternion& q2);

	// axisの周りを degree 度だけ回転するクオータニオンを作成
	static Quaternion angleAxis(const Vector3& axis, float degree);

	// 内積を求める
	static float dot(const Quaternion& q1, const Quaternion& q2);

	// 回転行列からクオータニオンを作成
	static Quaternion createFromRotationMatrix(const Matrix4& matrix);

	// 逆クオータニオンを返します
	static Quaternion inverse(Quaternion& rotation);

	// 正規化する
	static Quaternion normalize(const Quaternion& q);

	// 球面線形補間
	static Quaternion slerp(const Quaternion& value1, const Quaternion& value2, float amount);

	// 球面線形補間
	// ※未実装
	static Quaternion slerpUnclamped(const Quaternion& value1, const Quaternion& value2, float amount);

	// 単位クオータニオン
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
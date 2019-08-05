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

	// フォーマットされた文字列に変換
	std::string toString() const;

	// スケール行列を作成
	static Matrix4 createScale(const Vector3& scale);

	// 移動行列を作成
	static Matrix4 createTranslation(const Vector3& translation);

	// 任意の軸の回転行列を生成
	static Matrix4 createFromAxisAngle(const Vector3& axis, float degree);

	// クオータニオンから回転行列を生成
	// 「static Matrix4 rotate(const Quaternion& q);」と同じです
	static Matrix4 createFromQuaternion(const Quaternion& rotate);

	// ヨー、ピッチ、ロールで回転行列を生成
	static Matrix4 createFromYawPitchRoll(float yaw, float pitch, float roll);

	// x軸の回転行列を生成
	static Matrix4 createRotationX(float degree);

	// y軸の回転行列を生成
	static Matrix4 createRotationY(float degree);

	// z軸の回転行列を生成
	static Matrix4 createRotationZ(float degree);

	// ワールド行列を生成
	static Matrix4 createWorld(const Vector3& scale, const Quaternion& rotation, const Vector3& translation);

	// ワールド行列を生成
	static Matrix4 createWorld(const Vector3& scale, const Matrix4& rotation, const Vector3& translation);

	// 左手座標系のワールド行列を生成（DirectX等）
	static Matrix4 createWorldLH(const Vector3& position, const Vector3& forward, const Vector3& up);

	// 右手座標系のワールド行列を生成（OpenGL等）
	static Matrix4 createWorldRH(const Vector3& position, const Vector3& forward, const Vector3& up);

	// 左手座標系のパースペクティブ射影行列を生成（DirectX等）
	static Matrix4 createPerspectiveFieldOfViewLH(float fov, float aspect, float near, float far);

	// 右手座標系のパースペクティブ射影行列を生成（OpenGL等）
	static Matrix4 createPerspectiveFieldOfViewRH(float fov, float aspect, float near, float far);

	// 左手座標系のビュー行列を生成（DirectX等）
	static Matrix4 createLookAtLH(const Vector3& position, const Vector3& target, const Vector3& up);

	// 右手座標系のビュー行列を生成（OpenGL等）
	static Matrix4 createLookAtRH(const Vector3& position, const Vector3& target, const Vector3& up);

	// スクリーン座標系に変換する行列を生成
	static Matrix4 createScreen(float x, float y, float width, float height);

	// 逆行列を生成
	static Matrix4 invert(const Matrix4& matrix);

	// 逆行列を生成（回転と平行移動のみ）
	static Matrix4 invertFast(const Matrix4& matrix);

	// 行列の行と列を入れ替えます。
	static Matrix4 transpose(const Matrix4& matrix);

	// 2つの行列の対応する値の間を線形補間します
	static Matrix4 lerp(const Matrix4& value1, const Matrix4& value2, float amount);

	// 3D スケール / 回転 / 変換(SRT) Matrix からスカラー、変換、回転のコンポーネントを取得します
	void decompose(Vector3& scale, Quaternion& rotation, Vector3& translation) const;

	// 回転行列を正規化します。
	static Matrix4 normalizeRotationMatrix(const Matrix4& matrix);

	// 回転行列を正規化します。
	Matrix4& normalizeRotationMatrix();

	// 左手座標系の前方ベクトルを取得（DirectX等）
	Vector3 forwardLH() const;

	// 右手座標系の前方ベクトルを取得（OpenGL等）
	Vector3 forwardRH() const;

	// 左手座標系の前方ベクトルを設定（DirectX等）
	Matrix4& forwardLH(const Vector3& forward);

	// 右手座標系の前方ベクトルを設定（OpenGL等）
	Matrix4& forwardRH(const Vector3& forward);

	// 左手座標系の後方ベクトルを取得（DirectX等）
	Vector3 backwardLH() const;

	// 右手座標系の後方ベクトルを取得（OpenGL等）
	Vector3 backwardRH() const;

	// 左手座標系の後方ベクトルを設定（DirectX等）
	Matrix4& backwardLH(const Vector3& bakward);

	// 右手座標系の後方ベクトルを設定（OpenGL等）
	Matrix4& backwardRH(const Vector3& bakward);

	// 上方ベクトルを取得
	Vector3 up() const;

	// 上方ベクトルを設定
	Matrix4& up(const Vector3& up);

	// 下方ベクトルを取得
	Vector3 down() const;

	// 下方ベクトルを設定
	Matrix4& down(const Vector3& down);

	// 左ベクトルを取得
	Vector3 left() const;

	// 左ベクトルを設定
	Matrix4& left(const Vector3& left);

	// 右ベクトルを取得
	Vector3 right() const;

	// 右ベクトルを設定
	Matrix4& right(const Vector3& rignt);

	// 平行移動ベクトルを取得
	Vector3 translation() const;

	// 平行移動ベクトルを設定
	Matrix4& translation(const Vector3& translation);

	// スケール値を取得
	Vector3 scale() const;

	// 回転の取得
	Quaternion rotation() const;

	// 回転行列の取得
	Matrix4 rotationMatrix() const;

	// 逆行列を取得
	Matrix4 inverse() const;

	// 転置行列の取得
	Matrix4 transpose() const;

	// 移動回転スケーリングの設定を行う
	void setTRS(const Vector3& t, const Quaternion& r, const Vector3& s);

	// 単位行列
	static const Matrix4 identity;

	// ゼロ行列
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
#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>
#include <TktkMath/Matrix3.h>
#include <TktkMath/Vector2.h>

// 画像とそのアニメーションを管理するクラス
class Sprite
{
public:

	// 反転ビットフラグ
	enum ReverseFlag
	{
		// 水平方向の反転（垂直な線を軸にして反転）
		HORIZONTAL_REVERSE	= 1 << 0,

		// 垂直方向の反転（垂直な線を軸にして反転）
		VERTICAL_REVERSE	= 1 << 1,

		// 反転無し
		NOT_REVERSE = 0,
	};

	static void initialize();

	// ・分割していない画像の描画
	static void drawSprite(int id, const Matrix3& pose, const Vector2& center = Vector2(0.5f, 0.5f), unsigned int reverseFlag = NOT_REVERSE);

	// ・分割していない画像を(x, y)から(w, h)だけ切り取った画像の描画
	static void drawSprite(int id, int x, int y, int w, int h, const Matrix3& pose, const Vector2& center = Vector2(0.5f, 0.5f), unsigned int reverseFlag = NOT_REVERSE);

	// ・分割した画像の描画
	static void drawSprite(int id, int splitGraphIndex, const Matrix3& pose, const Vector2& center = Vector2(0.5f, 0.5f), unsigned int reverseFlag = NOT_REVERSE);

	// ・分割した画像を(x, y)から(w, h)だけ切り取った画像の描画
	static void drawSprite(int id, int splitGraphIndex, int x, int y, int w, int h, const Matrix3& pose, const Vector2& center = Vector2(0.5f, 0.5f), unsigned int reverseFlag = NOT_REVERSE);

	// ・引数のIDにテクスチャデータが関連付けられていない場合、処理を行わない
	static void erase(int id);

	// ・引数の画像の大きさを取得
	static Vector2 getSpriteSize(int id);

	static Vector2 getSpriteSize(int id, int splitGraphIndex);

	static void finalize();
};

#endif // !SPRITE_H_
#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>
#include <TktkMath/Vector2.h>

// 画像とそのアニメーションを管理するクラス
class Sprite
{
public:

	static void initialize();

	// ・分割していない画像の描画
	static void drawSprite(int id, const Vector2& position, const Vector2& center = Vector2::zero, const Vector2& scale = Vector2::one, float rotationDeg = 0.0f);

	// ・分割していない画像を(x, y)から(w, h)だけ切り取った画像の描画
	static void drawSprite(int id, const Vector2& position, int x, int y, int w, int h, const Vector2& center = Vector2::zero, const Vector2& scale = Vector2::one, float rotationDeg = 0.0f);

	// ・分割した画像の描画
	static void drawSprite(int id, int splitGraphIndex, const Vector2& position, const Vector2& center = Vector2::zero, const Vector2& scale = Vector2::one, float rotationDeg = 0.0f);

	// ・分割した画像を(x, y)から(w, h)だけ切り取った画像の描画
	static void drawSprite(int id, int splitGraphIndex, const Vector2& position, int x, int y, int w, int h, const Vector2& center = Vector2::zero, const Vector2& scale = Vector2::one, float rotationDeg = 0.0f);

	// ・引数のIDにテクスチャデータが関連付けられていない場合、処理を行わない
	static void erase(int id);

	// ・引数の画像の大きさを取得
	static Vector2 getSpriteSize(int id);

	static Vector2 getSpriteSize(int id, int splitGraphIndex);

	static void finalize();
};

#endif // !SPRITE_H_
#ifndef SPRITE_2D_DRAWER_H_
#define SPRITE_2D_DRAWER_H_

#include <TktkMath/Vector2.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include <TktkAppend2DComponent/Transform2D.h>

// ２次元画像を描画するコンポーネント
// 【前提コンポーネント：Transform2D】
class Sprite2dDrawer
	: public ComponentBase
{
public:

	Sprite2dDrawer(
		float drawPriority,											// 描画するレイヤーの種類
		int spriteId,												// 描画する画像の種類
		const Vector2& spriteCenterPosRate = Vector2(0.5f, 0.5f)	// 描画する画像の中心位置（割合 0.0～1.0）
	);

	Sprite2dDrawer(
		float drawPriority,											// 描画するレイヤーの種類
		int spriteId,												// 描画する画像の種類
		int splitGraphIndex,										// 描画する画像の分割番号
		const Vector2& spriteCenterPosRate = Vector2(0.5f, 0.5f)	// 描画する画像の中心位置（割合 0.0～1.0）
	);

public:

	void update();
	void draw() const;

public:

	// スプライトIDの再設定
	void setSpriteId(int spriteId);

	// 画像切り抜き読み込みのスプライトID
	// -1を入力すると切り抜かずに描画する
	void setSplitGraphIndex(int splitGraphIndex);

	// スプライトの中心座標（割合）を設定
	void setSpriteCenterPosRate(const Vector2& spriteCenterPosRate = Vector2(0.5f, 0.5f));

	// スプライトに使用する画像を切り抜いて表示するか？
	void useClipping(
		const Vector2& clippingLeftTopPos,		// 切り抜く左上座標
		const Vector2& clippingRightBottomPos	// 切り抜く右下座標
		);

private:

	std::weak_ptr<Transform2D> m_transform2D;

	int m_spriteId{ -1 };

	int m_splitGraphIndex{ -1 };

	Vector2 m_spriteCenterPosRate{ Vector2(0.5f, 0.5f) };

	bool m_useClipping{ false };

	Vector2 m_clippingLeftTopPos{ Vector2::zero };

	Vector2 m_clippingRightBottomPos{ Vector2::one };
};
#endif // !SPRITE_2D_DRAWER_H_
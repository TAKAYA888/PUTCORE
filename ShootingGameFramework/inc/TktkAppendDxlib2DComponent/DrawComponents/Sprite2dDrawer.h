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

	// 反転ビットフラグ
	enum ReverseFlag
	{
		// 水平方向の反転（垂直な線を軸にして反転）
		HORIZONTAL_REVERSE = 1 << 0,

		// 垂直方向の反転（水平な線を軸にして反転）
		VERTICAL_REVERSE = 1 << 1,

		// 反転無し
		NOT_REVERSE = 0,
	};

public:

	Sprite2dDrawer(
		float drawPriority,											// 描画するレイヤーの種類
		int spriteId,												// 描画する画像の種類
		const Vector2& spriteCenterPosRate = Vector2(0.5f, 0.5f),	// 描画する画像の中心位置（割合 0.0～1.0）
		float blendParam = 1.0f,									// 描画する画像の透過度
		unsigned int reverseFlag = NOT_REVERSE						// 描画する画像を反転するか
	);

	Sprite2dDrawer(
		float drawPriority,											// 描画するレイヤーの種類
		int spriteId,												// 描画する画像の種類
		int splitGraphIndex,										// 描画する画像の分割番号
		const Vector2& spriteCenterPosRate = Vector2(0.5f, 0.5f),	// 描画する画像の中心位置（割合 0.0～1.0）
		float blendParam = 1.0f,									// 描画する画像の透過度
		unsigned int reverseFlag = NOT_REVERSE						// 描画する画像を反転するか
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

	// 描画する画像の透過度を再設定
	void setBlendParam(float blendParam);

	// 描画する画像の透過度を取得
	float getBlendParam() const;

	// 描画する画像を反転フラグを再設定
	void setReverseFlag(unsigned int reverseFlag);

private:

	std::weak_ptr<Transform2D> m_transform2D;

	int m_spriteId{ -1 };

	int m_splitGraphIndex{ -1 };

	Vector2 m_spriteCenterPosRate{ Vector2(0.5f, 0.5f) };

	float m_blendParam;

	unsigned int m_reverseFlag{ NOT_REVERSE };

	bool m_useClipping{ false };

	Vector2 m_clippingLeftTopPos{ Vector2::zero };

	Vector2 m_clippingRightBottomPos{ Vector2::one };
};
#endif // !SPRITE_2D_DRAWER_H_
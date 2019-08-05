#pragma once

#include <memory>
#include <vector>
#include <TktkMath/Vector2.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include <TktkAppend2DComponent/Transform2D.h>
#include "Sprite2dDrawer.h"

// Sprite2dDrawerの画像をアニメーションさせる
// 【前提コンポーネント：Sprite2dDrawer】
class AnimatedSprite2d
	: public ComponentBase
{
public:

	AnimatedSprite2d(
		const std::vector<int>& animationIdList,	// アニメーションで使用する画像の種類の配列
		float animationIntervalSec,					// アニメーションで画像が切り替わる間隔（秒）
		bool isLoop									// アニメーションをループさせるか？
	);

	AnimatedSprite2d(
		int spriteId,									// アニメーションで使用する画像の種類
		const std::vector<int>& splitGraphIndexList,	// アニメーションで使用する画像分割番号の配列
		float animationIntervalSec,						// アニメーションで画像が切り替わる間隔（秒）
		bool isLoop										// アニメーションをループさせるか？
	);

	AnimatedSprite2d(
		int spriteId,					// アニメーションで使用する画像の種類
		int minSplitGraphIndex,			// 最小の画像分割番号
		int maxSplitGraphIndex,			// 最大の画像分割番号
		float animationIntervalSec,		// アニメーションで画像が切り替わる間隔（秒）
		bool isLoop,					// アニメーションをループさせるか？
		int initSplitGraphIndex = 0		// アニメーションの開始位置
	);

public:

	void start();

	void update();

private:

	std::weak_ptr<Sprite2dDrawer> m_sprite2dDrawer;

	int m_useSpriteId{ -1 };

	std::vector<int> m_animationIdList;

	size_t m_curAnimationIdIndex{ 0u };

	float m_animationTimer{ 0.0f };

	float m_animationIntervalSec;

	bool m_isLoop;

	bool m_useSplitGraphIndex;
};
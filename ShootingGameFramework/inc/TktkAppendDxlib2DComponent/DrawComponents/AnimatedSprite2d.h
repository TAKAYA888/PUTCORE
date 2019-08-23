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
		bool isLoop,								// アニメーションをループさせるか？
		float animSpeedRate = 1.0f					// アニメーションの再生倍率
	);

	AnimatedSprite2d(
		int spriteId,									// アニメーションで使用する画像の種類
		const std::vector<int>& splitGraphIndexList,	// アニメーションで使用する画像分割番号の配列
		float animationIntervalSec,						// アニメーションで画像が切り替わる間隔（秒）
		bool isLoop,									// アニメーションをループさせるか？
		float animSpeedRate = 1.0f						// アニメーションの再生倍率
	);

	AnimatedSprite2d(
		int spriteId,					// アニメーションで使用する画像の種類
		int minSplitGraphIndex,			// 最小の画像分割番号
		int maxSplitGraphIndex,			// 最大の画像分割番号
		float animationIntervalSec,		// アニメーションで画像が切り替わる間隔（秒）
		bool isLoop,					// アニメーションをループさせるか？
		float animSpeedRate = 1.0f		// アニメーションの再生倍率
	);

public:

	void update();

public:

	void setAnimSpeedRate(float animSpeedRate);

	float getAnimSpeedRate() const;

	void setIsLoop(bool isLoop);

	bool getIsLoop() const;

private:

	std::weak_ptr<Sprite2dDrawer> m_sprite2dDrawer;

	int m_useSpriteId{ -1 };

	std::vector<int> m_animationIdList;

	// アニメーションの再生速度倍率
	float m_animSpeedRate{ 1.0f };

	// アニメーションの経過時間（秒）
	float m_animationTimer{ 0.0f };

	// アニメーションの合計時間（秒）
	float m_animationTotalTime{ 0.0f };

	// アニメーションで使用する静止画１枚当たりの時間（秒）
	float m_animationIntervalSec;

	bool m_isLoop;

	bool m_useSplitGraphIndex;
};
#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "BossDeadScript.h"

struct BossDead
{
	static void create(const Vector2& position)
	{
		//ゲームオブジェクトを生成
		auto bossDead = std::make_shared<GameObject>();

		//2次元座標
		bossDead->addComponent(std::make_shared<Transform2D>(
			position,
			Vector2(2.0f, 2.0f),
			0.0f
			));

		//2次元座標の描画
		bossDead->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_EFFECT,
			IMAGE_BOSS_DEAD,
			0,
			Vector2(0.5f, 0.5f)
			));

		//2次元画像をアニメーションさせるコンポーネント
		bossDead->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_BOSS_DEAD,
			0,
			4,
			0.4f,
			false
			));

		//テレポのスクリプトを生成する
		bossDead->addComponent(std::make_shared<BossDeadScript>());

		//ゲームオブジェクト
		GameObjectManager::addGameObject(bossDead);
	};
};
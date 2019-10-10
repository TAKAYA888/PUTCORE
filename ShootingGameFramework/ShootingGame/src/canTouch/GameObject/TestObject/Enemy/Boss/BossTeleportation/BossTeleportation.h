#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "BossTeleportationScript.h"

struct BossTeleportation
{
	static void create(const Vector2& position)
	{
		//ゲームオブジェクトを生成
		auto bossteleportation = std::make_shared<GameObject>();

		//2次元座標
		bossteleportation->addComponent(std::make_shared<Transform2D>(
			position,
			Vector2(1.0f, 1.0f),
			0.0f
			));

		//2次元座標の描画
		bossteleportation->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_EFFECT,
			IMAGE_BOSS_TELEPORTATION,
			0,
			Vector2(0.5f, 0.5f)
			));

		//2次元画像をアニメーションさせるコンポーネント
		bossteleportation->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_BOSS_TELEPORTATION,
			0,
			4,
			0.04f,
			false
			));

		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
		bossteleportation->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		//テレポのスクリプトを生成する
		bossteleportation->addComponent(std::make_shared<BossTeleportationScript>());

		//ゲームオブジェクト
		GameObjectManager::addGameObject(bossteleportation);
	}
};
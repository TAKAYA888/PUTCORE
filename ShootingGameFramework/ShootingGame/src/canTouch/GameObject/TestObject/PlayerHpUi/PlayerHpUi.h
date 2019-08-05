#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "PlayerHpUiScript.h"

struct PlayerHpUi
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto playerHpUi = std::make_shared<GameObject>();

		// ２次元座標
		playerHpUi->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		playerHpUi->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
			IMAGE_PLAYER_HP_GAUGE,	// 描画する画像のID
			Vector2(0.0f, 0.5f)		// 画像の中心（割合）
			));

		// プレイヤーの体力バーのスクリプト
		playerHpUi->addComponent(std::make_shared<PlayerHpUiScript>(
			10.0f					// HPゲージの横幅（元画像の何倍か？）
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(playerHpUi);
	}
};
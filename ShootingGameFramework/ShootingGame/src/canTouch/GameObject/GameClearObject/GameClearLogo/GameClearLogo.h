#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "GameClearLogoScript.h"

struct GameClearLogo
{
	static void create()
	{
		// ゲームオブジェクトを作成
		auto gameClearLogo = std::make_shared<GameObject>();

		// ２次元座標
		gameClearLogo->addComponent(std::make_shared<Transform2D>(
			SCREEN_SIZE / 2.0f,		// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		gameClearLogo->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_BACK_GROUND,	// 描画するレイヤー
			IMAGE_CLEAR_LOGO,		// 描画する画像のID
			Vector2(0.5f, 0.5f)		// 画像の中心（割合）
			));

		// タイトルロゴのスクリプト
		gameClearLogo->addComponent(std::make_shared<GameClearLogoScript>());

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(gameClearLogo);
	}
};
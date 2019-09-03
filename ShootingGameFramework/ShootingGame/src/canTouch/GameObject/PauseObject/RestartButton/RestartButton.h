#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "RestartButtonScript.h"

struct RestartButton
{
	static void create(const Vector2& initPos)
	{
		// ゲームオブジェクトを作成
		auto restartbutton = std::make_shared<GameObject>();

		// ２次元座標
		restartbutton->addComponent(std::make_shared<Transform2D>(
			SCREEN_SIZE / 1.5f,		// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		restartbutton->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,	// 描画するレイヤー
			IMAGE_PAUSE_BACK,		// 描画する画像のID
			Vector2(0.5f, 0.5f)		// 画像の中心（割合）
			));

		// 2次元の座標のクランパー(追加)
		restartbutton->addComponent(std::make_shared<PositionClamper>(
			Vector2(SCREEN_SIZE.x / 2, 000.0f),			// 最小座標
			Vector2(SCREEN_SIZE.x / 2, 500.0f)			// 最大座標
			));


		// タイトルロゴのスクリプト
		restartbutton->addComponent(std::make_shared<RestartButtonScript>());

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(restartbutton);
	}
};

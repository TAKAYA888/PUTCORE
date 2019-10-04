#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "ScoreScript.h"

struct Score
{
	static void create()
	{
		// ゲームオブジェクトを作成
		auto Score = std::make_shared<GameObject>();

		// ２次元座標
		Score->addComponent(std::make_shared<Transform2D>(
			SCREEN_SIZE * 0.5f,		// 座標（引数から受け取る）
			Vector2(1.5f, 1.5f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// タイトルロゴのスクリプト
		Score->addComponent(std::make_shared<ScoreScript>());

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(Score);
	}
};
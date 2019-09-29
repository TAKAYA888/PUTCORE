#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "ResultLogoScript.h"

struct ResultLogo
{
	static void create()
	{
		// ゲームオブジェクトを作成
		auto resultLogo = std::make_shared<GameObject>();

		// ２次元座標
		resultLogo->addComponent(std::make_shared<Transform2D>(
			0.0f,		// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		resultLogo->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_BACK_GROUND,	// 描画するレイヤー
			IMAGE_RESULT_LOGO,		// 描画する画像のID
			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
			));

		// タイトルロゴのスクリプト
		resultLogo->addComponent(std::make_shared<ResultLogoScript>());

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(resultLogo);
	}
};
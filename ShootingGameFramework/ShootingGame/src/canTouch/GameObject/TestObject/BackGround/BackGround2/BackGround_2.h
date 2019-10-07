#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "BackGround_2Script.h"

struct BackGround_2
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto background_2 = std::make_shared<GameObject>();

		// タグを設定
		background_2->setTag(AKITA_BANZAI);

		// ２次元座標
		background_2->addComponent(std::make_shared<Transform2D>(
			position,		// 座標（引数から受け取る）
			Vector2(1.5f, 1.5f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		background_2->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_BACK_GROUND,	// 描画するレイヤー
			IMAGE_PLAY_BG2,		// 描画する画像のID
			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
			));

		// タイトルロゴのスクリプト
		background_2->addComponent(std::make_shared<BackGround_2Script>());

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(background_2);
	}
};


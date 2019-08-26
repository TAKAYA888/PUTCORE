#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "Push_SpaceScript.h"

struct Push_Space
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto push_space = std::make_shared<GameObject>();

		// ２次元座標
		push_space->addComponent(std::make_shared<Transform2D>(
			position,		// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		push_space->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,	// 描画するレイヤー
			IMAGE_PUSH_SPACE,		// 描画する画像のID
			Vector2(0.5f, 0.5f)		// 画像の中心（割合）
			));

		// サウンドを再生するコンポーネント
		push_space->addComponent(std::make_shared<SePlayer>(
			INPUT_SE 	// サウンドの名前
			));

		// プッシュスペースのスクリプト
		push_space->addComponent(std::make_shared<Push_SpaceScript>());

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(push_space);
	}
};

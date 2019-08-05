#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "GameStartItemScript.h"

struct GameStartItem
{
	static void create(const Vector2& initPos)
	{
		// ゲームオブジェクトを作成
		auto gameStartItem = std::make_shared<GameObject>();

		// タグを設定
		gameStartItem->setTag(GAME_OBJECT_TAG_MENU_ITEM);

		// ２次元座標
		gameStartItem->addComponent(std::make_shared<Transform2D>(
			initPos,				// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// 長方形の当たり判定
		gameStartItem->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_MENU_ITEM,	// 衝突判定のグループ
			Vector2(640.0f, 128.0f)	// 衝突判定の大きさ
			));

		// 長方形の当たり判定の範囲の描画
		gameStartItem->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// 描画するレイヤー
			Color::red				// 当たり判定の範囲の色
			));

		// ２次元画像の描画
		gameStartItem->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI - 0.1f,	// 描画するレイヤー
			IMAGE_TITLE_MENU_GAMESTART,		// 描画する画像のID
			Vector2(0.5f, 0.5f)		// 画像の中心（割合）
			));

		// ゲーム開始のメニュー項目のスクリプト
		gameStartItem->addComponent(std::make_shared<GameStartItemScript>());

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(gameStartItem);
	}
};
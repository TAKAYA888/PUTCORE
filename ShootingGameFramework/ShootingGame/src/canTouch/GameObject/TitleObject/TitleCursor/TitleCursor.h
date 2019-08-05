#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "TitleCursorScript.h"

struct TitleCursor
{
	static void create()
	{
		// ゲームオブジェクトを作成
		auto titleCursor = std::make_shared<GameObject>();

		// タグを設定
		titleCursor->setTag(GAME_OBJECT_TAG_CURSOR);

		// ２次元座標
		titleCursor->addComponent(std::make_shared<Transform2D>(
			SCREEN_SIZE / 2.0f,		// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// 円の当たり判定
		titleCursor->addComponent(std::make_shared<CircleCollider>(
			COLLISION_GROUP_CURSOR,			// 衝突判定のグループ
			32.0f							// 衝突判定の半径
			));

		// 円の当たり判定の範囲の描画
		titleCursor->addComponent(std::make_shared<CircleColliderWireFrameDrawer>(
			DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// 描画するレイヤー
			Color::red				// 当たり判定の範囲の色
			));

		// ２次元画像の描画
		titleCursor->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,	// 描画するレイヤー
			IMAGE_TITLE_CURSOR,		// 描画する画像のID
			Vector2(0.5f, 0.5f)		// 画像の中心（割合）
			));

		// タイトルカーソルのスクリプト
		titleCursor->addComponent(std::make_shared<TitleCursorScript>());

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(titleCursor);
	}
};
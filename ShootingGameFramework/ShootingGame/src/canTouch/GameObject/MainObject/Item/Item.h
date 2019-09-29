#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "ItemScript.h"

struct Item
{
	static void create(const Vector2& position, float rotationDeg)
	{
		auto item  = std::make_shared<GameObject>();

		// タグを設定
		item->setTag(GameObjectTag::GAME_OBJECT_TAG_ITEM);

		// ２次元座標
		item->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			rotationDeg				// 回転（引数から受け取る・度数法）
			));

		// ２次元の慣性移動
		item->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// 減速率
			));

		// 画面外に出たら消す
		item->addComponent(std::make_shared<OutScreenSelfDestroyer2D>(
			Vector2::zero,			// 最小座標
			SCREEN_SIZE				// 最大座標
			));

		// 長方形の当たり判定
		item->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_ITEM,	// 衝突判定のグループ
			Vector2(32.0f, 32.0f)	// 衝突判定の大きさ
			));

		// 長方形の当たり判定の範囲の描画
		item->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// 描画するレイヤー
			Color::red				// 当たり判定の範囲の色
			));

		// ２次元画像の描画
		item->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_ENEMY,			// 描画するレイヤー
			IMAGE_ENEMY,				// 描画する画像のID
			Vector2(0.5f, 0.5f)		// 画像の中心（割合）
			));
		
		// エネミーのスクリプト
		item->addComponent(std::make_shared<ItemScript>());

		GameObjectManager::addGameObject(item);
	}
};
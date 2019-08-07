#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "PlayerScript.h"

struct Player
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto player = std::make_shared<GameObject>();

		// タグを設定
		player->setTag(GAME_OBJECT_TAG_PLAYER);

		// ２次元座標
		player->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元の慣性移動
		player->addComponent(std::make_shared<InertialMovement2D>(
			100.0f					// 減速率
			));

		// 2次元の座標のクランパー
		player->addComponent(std::make_shared<PositionClamper>(
			Vector2::zero,			// 最小座標
			SCREEN_SIZE				// 最大座標
			));


		// 円の当たり判定
		player->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_PLAYER,	// 衝突判定のグループ
			Vector2(32.0f, 32.0f),   // 衝突判定の半径
			Vector2(15, -10)
			));

		// 円の当たり判定の範囲の描画
		player->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// 描画するレイヤー
			Color::red				// 当たり判定の範囲の色
			));

		// ２次元画像の描画
		player->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_PLAYER,			// 描画するレイヤー
			IMAGE_PLAYER,			// 描画する画像のID
			Vector2(0.5f, 0.5f)		// 画像の中心（割合）
			));

		// プレイヤーのスクリプト
		player->addComponent(std::make_shared<PlayerScript>(
			500.0f	// 移動速度
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(player);
	}
};
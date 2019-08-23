#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "VirusEnemyScript1-1.h"

struct VirusEnemy1_1
{
	static void create(const Vector2& position, float rotationDeg)
	{
		auto virusenemy1_1 = std::make_shared<GameObject>();

		// タグを設定
		virusenemy1_1->setTag(GameObjectTag::GAME_OBJECT_TAG_VIRYS_ENEMY1);

		// ２次元座標
		virusenemy1_1->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			rotationDeg				// 回転（引数から受け取る・度数法）
			));

		// ２次元の慣性移動
		virusenemy1_1->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// 減速率
			));

		// 画面外に出たら消す
		virusenemy1_1->addComponent(std::make_shared<OutScreenSelfDestroyer2D>(
			Vector2::zero,			// 最小座標
			SCREEN_SIZE				// 最大座標
			));

		// 長方形の当たり判定
		virusenemy1_1->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_ENEMY,	// 衝突判定のグループ
			Vector2(64.0f, 64.0f)	// 衝突判定の大きさ
			));

		// 長方形の当たり判定の範囲の描画
		virusenemy1_1->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// 描画するレイヤー
			Color::red				// 当たり判定の範囲の色
			));

		// ２次元画像の描画
		virusenemy1_1->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_ENEMY,			// 描画するレイヤー
			IMAGE_VIRUS_ENEMY_TWO,0,						// 描画する画像のID				
			Vector2(0.5f, 0.5f)		// 画像の中心（割合）
			));

		virusenemy1_1->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_VIRUS_ENEMY_TWO,
			0,
			4,
			0.1f,
			true
			));


		// エネミーのスクリプト
		virusenemy1_1->addComponent(std::make_shared<VirusEnemyScript1_1>());

		GameObjectManager::addGameObject(virusenemy1_1);
	}
};
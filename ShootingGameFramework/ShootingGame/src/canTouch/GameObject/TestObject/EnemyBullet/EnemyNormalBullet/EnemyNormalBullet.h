#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "EnemyNormalBulletScript.h"

struct EnemyNormalBullet
{
	static void create(const Vector2& position, const Vector2& initVelocity)
	{
		// ゲームオブジェクトを作成
		auto enemyNormalBullet = std::make_shared<GameObject>();

		// タグを設定
		enemyNormalBullet->setTag(GAME_OBJECT_TAG_ENEMY_BULLET);

		// ２次元座標
		enemyNormalBullet->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(0.2f, 0.2f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元の慣性移動
		enemyNormalBullet->addComponent(std::make_shared<InertialMovement2D>(
			0.0f,					// 減速率
			initVelocity			// 初期速度
			));

		// 画面外に出たら消す
		enemyNormalBullet->addComponent(std::make_shared<OutScreenSelfDestroyer2D>(
			Vector2::zero,			// 最小座標
			SCREEN_SIZE				// 最大座標
			));

		// 円の当たり判定
		enemyNormalBullet->addComponent(std::make_shared<CircleCollider>(
			COLLISION_GROUP_ENEMY_BULLET,	// 衝突判定のグループ
			8.0f							// 衝突判定の半径
			));

		// 円の当たり判定の範囲の描画
		//enemyNormalBullet->addComponent(std::make_shared<CircleColliderWireFrameDrawer>(
		//	DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// 描画するレイヤー
		//	Color::red				// 当たり判定の範囲の色
		//	));

		// ２次元画像の描画
		enemyNormalBullet->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_PLAYER_BULLET,	// 描画するレイヤー
			IMAGE_PLAYER_BULLET,	// 描画する画像のID
			Vector2(0.5f, 0.5f)		// 画像の中心（割合）
			));

		// エネミーの通常弾のスクリプト
		enemyNormalBullet->addComponent(std::make_shared<EnemyNormalBulletScript>());

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(enemyNormalBullet);
	}
};
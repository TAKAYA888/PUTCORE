#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "Boss3Script.h"

struct Boss3
{
	static void create(const Vector2& position, float rotationDeg)
	{
		auto Boss3 = std::make_shared<GameObject>();

		// タグを設定
		Boss3->setTag(GameObjectTag::GAME_OBJECT_TAG_ENEMY);

		// ２次元座標
		Boss3->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(2.0f, 2.0f),	// スケール（倍率）
			rotationDeg				// 回転（引数から受け取る・度数法）
			));

		// ２次元の慣性移動
		Boss3->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// 減速率
			));



		// 長方形の当たり判定
		Boss3->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_ENEMY,	// 衝突判定のグループ
			Vector2(128.0f, 128.0f)	// 衝突判定の大きさ
			));

		// 長方形の当たり判定の範囲の描画
		Boss3->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// 描画するレイヤー
			Color::red				// 当たり判定の範囲の色
			));

		// ２次元画像の描画
		Boss3->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_ENEMY,// 描画するレイヤー
			IMAGE_BOSS_DEAD,
			1,						// 描画する画像のID				
			Vector2(0.5f, 0.5f)		// 画像の中心（割合）
			));



		// エネミーのスクリプト
		Boss3->addComponent(std::make_shared<Boss3Script>());

		GameObjectManager::addGameObject(Boss3);
	}
};
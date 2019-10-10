
#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "CoreScript.h"
#include "../setCore/setCoreScript.h"

struct Core
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto core = std::make_shared<GameObject>();

		// タグを設定
		core->setTag(GAME_OBJECT_TAG_CORE);

		// ２次元座標
		core->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(2.0f, 2.0f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元の慣性移動
		core->addComponent(std::make_shared<InertialMovement2D>(
			10.0f					// 減速率
			));

		// 2次元の座標のクランパー
		core->addComponent(std::make_shared<PositionClamper>(
			Vector2::zero,			// 最小座標
			Vector2(SCREEN_SIZE_X + 200.0f, SCREEN_SIZE_Y)// 最大座標
			));

		core->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_CORE,	// アニメーションで使用する画像の種類
			0,					// 最小の左上基準の画像番号
			5,					// 最大の左上基準の画像番号
			2.0f,				// 何秒間で次の画像に変わるか
			true				// アニメーションをループさせるか？		
			));

		// 長方形の当たり判定
		core->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_CORE,	// 衝突判定のグループ
			Vector2(50.0f, 20.0f)	// 衝突判定の大きさ
			));


		// 長方形の当たり判定の範囲の描画
		//core->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
		//	DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// 描画するレイヤー
		//	Color::red				// 当たり判定の範囲の色
		//	));

		// ２次元画像の描画
		core->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_PLAYER,			// 描画するレイヤー
			IMAGE_CORE,			// 描画する画像のID
			0,
			Vector2(0.5f, 0.5f)		// 画像の中心（割合）
			));

		// サウンドを再生するコンポーネント
		core->addComponent(std::make_shared<SePlayer>(
			player_bullet 	// サウンドの名前
			));

		// プレイヤーのスクリプト
		core->addComponent(std::make_shared<CoreScript>(
			));

		core->addComponent(std::make_shared<setCoreScript>(
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(core);
	}
};
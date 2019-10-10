
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

		// 2次元の座標のクランパー
		player->addComponent(std::make_shared<PositionClamper>(
			Vector2(95, 60),			// 最小座標
			Vector2(SCREEN_SIZE_X - 70.0f, SCREEN_SIZE_Y - 80.0f)				// 最大座標
			));

		// ２次元座標
		player->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(1.5f, 1.5f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元の慣性移動
		player->addComponent(std::make_shared<InertialMovement2D>(
			10.0f					// 減速率
			));

		// 円の当たり判定
		player->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_PLAYER,	// 衝突判定のグループ
			Vector2(30.0f, 25.0f),   // 衝突判定の半径
			Vector2(20, 5)
			));

		// 円の当たり判定の範囲の描画
		//player->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
		//	DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// 描画するレイヤー
		//	Color::red				// 当たり判定の範囲の色
		//	));

		// ２次元画像の描画
		player->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_PLAYER,			// 描画するレイヤー
			IMAGE_PLAYER,			// 描画する画像のID
			Vector2(0.5f, 0.5f)		// 画像の中心（割合）
			));

		player->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_PLAYER,	// アニメーションで使用する画像の種類
			0,					// 最小の左上基準の画像番号
			5,					// 最大の左上基準の画像番号
			0.01f,				// 何秒間で次の画像に変わるか
			true				// アニメーションをループさせるか？
			));

		// サウンドを再生するコンポーネント
		player->addComponent(std::make_shared<SePlayer>(
			INPUT_SE 	// サウンドの名前
			));

		// プレイヤーのスクリプト
		player->addComponent(std::make_shared<PlayerScript>(
			50.0f	// 移動速度
			));

		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
		player->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(player);
	}
};
#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "BacktoTitileItemScript.h"

struct BacktoTitileItem
{
	static void create(const Vector2& initPos)
	{
		// ゲームオブジェクトを作成
		auto backtoTitileItem = std::make_shared<GameObject>();

		// タグを設定
		backtoTitileItem->setTag(GAME_OBJECT_TAG_MENU_ITEM);

		// ２次元座標
		backtoTitileItem->addComponent(std::make_shared<Transform2D>(
			initPos,				// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// 長方形の当たり判定
		backtoTitileItem->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_MENU_ITEM,	// 衝突判定のグループ
			Vector2(400.0f, 100.0f)	// 衝突判定の大きさ
			));

		// 長方形の当たり判定の範囲の描画
		//stageSelectOneItem->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			//DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// 描画するレイヤー
			//Color::red				// 当たり判定の範囲の色
			//));

		// ２次元画像の描画
		backtoTitileItem->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI - 0.1f,	// 描画するレイヤー
			IMAGE_BACK_TO_TITLE2,		// 描画する画像のID
			Vector2(0.5f, 0.7f),	// 画像の中心（割合）
			0.0
			));

		// サウンドを再生するコンポーネント
		backtoTitileItem->addComponent(std::make_shared<SePlayer>(
			INPUT_SE	// サウンドの名前
			));

		//追加
		backtoTitileItem->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// 減速率
			));

		// ゲーム開始のメニュー項目のスクリプト
		//stageSelectOneItem->addComponent(std::make_shared<GameStartItemScript>());

		// プレイヤーのスクリプト（追加）
		backtoTitileItem->addComponent(std::make_shared<BacktoTitileItemScript>(
			32.0f	// 移動速度
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(backtoTitileItem);
	}
};

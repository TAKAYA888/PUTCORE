#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "SelectMenuItemScript.h"

struct SelectMenuItem
{
	static void create(const Vector2& initPos)
	{
		// ゲームオブジェクトを作成
		auto selectMenuItem = std::make_shared<GameObject>();

		// タグを設定
		selectMenuItem->setTag(GAME_OBJECT_TAG_MENU_ITEM);

		// ２次元座標
		selectMenuItem->addComponent(std::make_shared<Transform2D>(
			initPos,				// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// 長方形の当たり判定
		selectMenuItem->addComponent(std::make_shared<RectCollider>(
			COLLISION_GROUP_MENU_ITEM,	// 衝突判定のグループ
			Vector2(400.0f, 100.0f)	// 衝突判定の大きさ
			));

		// 長方形の当たり判定の範囲の描画
		//gameStartItem->addComponent(std::make_shared<RectColliderWireFrameDrawer>(
			//DrawPriority::DRAW_PRIORITY_DEBUG_FLAME,	// 描画するレイヤー
			//Color::red				// 当たり判定の範囲の色
			//));

		// ２次元画像の描画
		selectMenuItem->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI - 0.1f,	// 描画するレイヤー
			IMAGE_SELECT_MENU_STAGE,		// 描画する画像のID
			Vector2(0.5f, 0.5f),	// 画像の中心（割合）
			0.0
			));

		// サウンドを再生するコンポーネント
		selectMenuItem->addComponent(std::make_shared<SePlayer>(
			INPUT_SE	// サウンドの名前
			));

		//追加
		selectMenuItem->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// 減速率
			));


	


		// ゲーム開始のメニュー項目のスクリプト
		//gameStartItem->addComponent(std::make_shared<GameStartItemScript>());

		// プレイヤーのスクリプト（追加）
		selectMenuItem->addComponent(std::make_shared<SelectMenuItemScript>(
			32.0f	// 移動速度
			));


		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(selectMenuItem);


	}
};

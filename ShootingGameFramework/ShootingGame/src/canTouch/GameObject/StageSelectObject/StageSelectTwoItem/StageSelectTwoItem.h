#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "StageSelectTwoItemScript.h"

struct StageSelectTwoItem
{
	static void create(const Vector2& initPos)
	{
		// ゲームオブジェクトを作成
		auto stageSelectTwoItem = std::make_shared<GameObject>();

		// タグを設定
		stageSelectTwoItem->setTag(GAME_OBJECT_TAG_MENU_ITEM);

		// ２次元座標
		stageSelectTwoItem->addComponent(std::make_shared<Transform2D>(
			initPos,				// 座標（引数から受け取る）
			Vector2(1.5f, 1.5f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		

		// ２次元画像の描画
		stageSelectTwoItem->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI - 0.1f,	// 描画するレイヤー
			IMAGE_STAGE_SELECT_TWO,		// 描画する画像のID
			Vector2(0.5f, 2.0f),	// 画像の中心（割合）
			0.0
			));

		// サウンドを再生するコンポーネント
		stageSelectTwoItem->addComponent(std::make_shared<SePlayer>(
			INPUT_SE	// サウンドの名前
			));

		//追加
		stageSelectTwoItem->addComponent(std::make_shared<InertialMovement2D>(
			3.0f // 減速率
		    ));
		

		// プレイヤーのスクリプト（追加）
		stageSelectTwoItem->addComponent(std::make_shared<StageSelectTwoItemScript>(
			32.0f	// 移動速度
			));


		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(stageSelectTwoItem);


	}
};

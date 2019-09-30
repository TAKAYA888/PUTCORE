#pragma once
#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "TitleDummyItemScript.h"

struct TitleDummyItem
{
	static void create(const Vector2& initPos)
	{
		// ゲームオブジェクトを作成
		auto TitleDummyItem = std::make_shared<GameObject>();

		// タグを設定
		TitleDummyItem->setTag(GAME_OBJECT_TAG_MENU_ITEM);

		// ２次元座標
		TitleDummyItem->addComponent(std::make_shared<Transform2D>(
			initPos,				// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		TitleDummyItem->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI - 0.1f,	// 描画するレイヤー
			IMAGE_TITLE_MENU_DUMMY,		// 描画する画像のID
			Vector2(0.5f, 0.5f),	// 画像の中心（割合）
			0.0
			));

		// サウンドを再生するコンポーネント
		TitleDummyItem->addComponent(std::make_shared<SePlayer>(
			INPUT_SE	// サウンドの名前
			));

		//追加
		TitleDummyItem->addComponent(std::make_shared<InertialMovement2D>(
			3.0f					// 減速率
			));

		// 2次元の座標のクランパー(追加)
		TitleDummyItem->addComponent(std::make_shared<PositionClamper>(
			Vector2(SCREEN_SIZE.x / 2, 000.0f),			// 最小座標
			Vector2(SCREEN_SIZE.x / 2, 500.0f)			// 最大座標
			));

		// ゲーム開始のメニュー項目のスクリプト
		TitleDummyItem->addComponent(std::make_shared<TitleDummyItemScript>());

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(TitleDummyItem);
	}
};
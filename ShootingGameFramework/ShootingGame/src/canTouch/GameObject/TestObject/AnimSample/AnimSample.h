#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

struct AnimSample
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto animSample = std::make_shared<GameObject>();

		// ２次元座標
		animSample->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		animSample->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_PLAYER,			// 描画するレイヤー
			IMAGE_ANIM_SAMPLE,		// 描画する画像のID
			0,						// 左上から見て何番目の位置の画像を表示するか
			Vector2(0.5f, 0.5f)		// 画像の中心（割合）
			));

		// 
		animSample->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_ANIM_SAMPLE,	// アニメーションで使用する画像の種類
			0,					// 最小の左上基準の画像番号
			3,					// 最大の左上基準の画像番号
			0.1f,				// 何秒間で次の画像に変わるか
			true				// アニメーションをループさせるか？
			));

		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
		animSample->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(animSample);
	}
};
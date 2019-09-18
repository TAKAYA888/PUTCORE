#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"

//#include "../ResultObject/Score/ScoreScript.cpp"

#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

//MainSceneのスコア表示部（左から1）

struct Score_Screen_1
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto scoreScreen = std::make_shared<GameObject>();

		// ２次元座標
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(0.2f, 0.2f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
			SCORE_NUMBER,		// 描画する画像のID
			0,	// 左上から見て何番目の位置の画像を表示するか
			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
			));

		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(scoreScreen);
	}
};
//struct Score_Screen_2
//{
//	static void create(const Vector2& position)
//	{
//		// ゲームオブジェクトを作成
//		auto scoreScreen = std::make_shared<GameObject>();
//
//		// ２次元座標
//		scoreScreen->addComponent(std::make_shared<Transform2D>(
//			position,				// 座標（引数から受け取る）
//			Vector2(0.2f, 0.2f),	// スケール（倍率）
//			0.0f					// 回転（度数法）
//			));
//
//		// ２次元画像の描画
//		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
//			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
//			SCORE_NUMBER,		// 描画する画像のID
//			ScoreScript::score / 10000000,						// 左上から見て何番目の位置の画像を表示するか
//			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
//			));
//
//		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
//		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
//			DIE_GAMEPLAY_OBJECT
//			));
//
//		// ゲームオブジェクトを追加
//		GameObjectManager::addGameObject(scoreScreen);
//	}
//};
//struct Score_Screen_3
//{
//	static void create(const Vector2& position)
//	{
//		// ゲームオブジェクトを作成
//		auto scoreScreen = std::make_shared<GameObject>();
//
//		// ２次元座標
//		scoreScreen->addComponent(std::make_shared<Transform2D>(
//			position,				// 座標（引数から受け取る）
//			Vector2(0.2f, 0.2f),	// スケール（倍率）
//			0.0f					// 回転（度数法）
//			));
//
//		// ２次元画像の描画
//		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
//			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
//			SCORE_NUMBER,		// 描画する画像のID
//			ScoreScript::score / 1000000,						// 左上から見て何番目の位置の画像を表示するか
//			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
//			));
//
//		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
//		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
//			DIE_GAMEPLAY_OBJECT
//			));
//
//		// ゲームオブジェクトを追加
//		GameObjectManager::addGameObject(scoreScreen);
//	}
//};
//struct Score_Screen_4
//{
//	static void create(const Vector2& position)
//	{
//		// ゲームオブジェクトを作成
//		auto scoreScreen = std::make_shared<GameObject>();
//
//		// ２次元座標
//		scoreScreen->addComponent(std::make_shared<Transform2D>(
//			position,				// 座標（引数から受け取る）
//			Vector2(0.2f, 0.2f),	// スケール（倍率）
//			0.0f					// 回転（度数法）
//			));
//
//		// ２次元画像の描画
//		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
//			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
//			SCORE_NUMBER,		// 描画する画像のID
//			ScoreScript::score / 1000,						// 左上から見て何番目の位置の画像を表示するか
//			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
//			));
//
//		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
//		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
//			DIE_GAMEPLAY_OBJECT
//			));
//
//		// ゲームオブジェクトを追加
//		GameObjectManager::addGameObject(scoreScreen);
//	}
//};
//struct Score_Screen_5
//{
//	static void create(const Vector2& position)
//	{
//		// ゲームオブジェクトを作成
//		auto scoreScreen = std::make_shared<GameObject>();
//
//		// ２次元座標
//		scoreScreen->addComponent(std::make_shared<Transform2D>(
//			position,				// 座標（引数から受け取る）
//			Vector2(0.2f, 0.2f),	// スケール（倍率）
//			0.0f					// 回転（度数法）
//			));
//
//		// ２次元画像の描画
//		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
//			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
//			SCORE_NUMBER,		// 描画する画像のID
//			ScoreScript::Score_Screen_Number(5),						// 左上から見て何番目の位置の画像を表示するか
//			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
//			));
//
//		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
//		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
//			DIE_GAMEPLAY_OBJECT
//			));
//
//		// ゲームオブジェクトを追加
//		GameObjectManager::addGameObject(scoreScreen);
//	}
//};
//struct Score_Screen_6
//{
//	static void create(const Vector2& position)
//	{
//		// ゲームオブジェクトを作成
//		auto scoreScreen = std::make_shared<GameObject>();
//
//		// ２次元座標
//		scoreScreen->addComponent(std::make_shared<Transform2D>(
//			position,				// 座標（引数から受け取る）
//			Vector2(0.2f, 0.2f),	// スケール（倍率）
//			0.0f					// 回転（度数法）
//			));
//
//		// ２次元画像の描画
//		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
//			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
//			SCORE_NUMBER,		// 描画する画像のID
//			ScoreScript::Score_Screen_Number(6),						// 左上から見て何番目の位置の画像を表示するか
//			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
//			));
//
//		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
//		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
//			DIE_GAMEPLAY_OBJECT
//			));
//
//		// ゲームオブジェクトを追加
//		GameObjectManager::addGameObject(scoreScreen);
//	}
//};
//struct Score_Screen_7
//{
//	static void create(const Vector2& position)
//	{
//		// ゲームオブジェクトを作成
//		auto scoreScreen = std::make_shared<GameObject>();
//
//		// ２次元座標
//		scoreScreen->addComponent(std::make_shared<Transform2D>(
//			position,				// 座標（引数から受け取る）
//			Vector2(0.2f, 0.2f),	// スケール（倍率）
//			0.0f					// 回転（度数法）
//			));
//
//		// ２次元画像の描画
//		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
//			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
//			SCORE_NUMBER,		// 描画する画像のID
//			ScoreScript::Score_Screen_Number(7),						// 左上から見て何番目の位置の画像を表示するか
//			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
//			));
//
//		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
//		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
//			DIE_GAMEPLAY_OBJECT
//			));
//
//		// ゲームオブジェクトを追加
//		GameObjectManager::addGameObject(scoreScreen);
//	}
//};
//struct Score_Screen_8
//{
//	static void create(const Vector2& position)
//	{
//		// ゲームオブジェクトを作成
//		auto scoreScreen = std::make_shared<GameObject>();
//
//		// ２次元座標
//		scoreScreen->addComponent(std::make_shared<Transform2D>(
//			position,				// 座標（引数から受け取る）
//			Vector2(0.2f, 0.2f),	// スケール（倍率）
//			0.0f					// 回転（度数法）
//			));
//
//		// ２次元画像の描画
//		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
//			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
//			SCORE_NUMBER,		// 描画する画像のID
//			ScoreScript::Score_Screen_Number(8),						// 左上から見て何番目の位置の画像を表示するか
//			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
//			));
//
//		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
//		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
//			DIE_GAMEPLAY_OBJECT
//			));
//
//		// ゲームオブジェクトを追加
//		GameObjectManager::addGameObject(scoreScreen);
//	}
//};
//struct Score_Screen_9
//{
//	static void create(const Vector2& position)
//	{
//		// ゲームオブジェクトを作成
//		auto scoreScreen = std::make_shared<GameObject>();
//
//		// ２次元座標
//		scoreScreen->addComponent(std::make_shared<Transform2D>(
//			position,				// 座標（引数から受け取る）
//			Vector2(0.2f, 0.2f),	// スケール（倍率）
//			0.0f					// 回転（度数法）
//			));
//
//		// ２次元画像の描画
//		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
//			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
//			SCORE_NUMBER,		// 描画する画像のID
//			ScoreScript::Score_Screen_Number(9),						// 左上から見て何番目の位置の画像を表示するか
//			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
//			));
//
//		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
//		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
//			DIE_GAMEPLAY_OBJECT
//			));
//
//		// ゲームオブジェクトを追加
//		GameObjectManager::addGameObject(scoreScreen);
//	}
//};


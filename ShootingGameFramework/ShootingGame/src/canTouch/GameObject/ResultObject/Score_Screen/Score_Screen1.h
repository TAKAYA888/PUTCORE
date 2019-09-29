#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"

#include "Score_Screen_Script1.h"
#include "../Score/ScoreScript.h"

#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

//MainSceneのスコア表示部（左から1）

float size = 0.8f; // 文字サイズ

struct Score_Screen_1_1
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto scoreScreen = std::make_shared<GameObject>();

		// ２次元座標
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(size, size),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
			SCORE_NUMBER,		// 描画する画像のID
			ScoreScript::Score_Screen_Number(1),	// 左上から見て何番目の位置の画像を表示するか
			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
			));

		//特定のメッセージを受信したら自信を殺すコンポーネントを追加
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_2_1
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto scoreScreen = std::make_shared<GameObject>();

		// ２次元座標
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(size , size),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
			SCORE_NUMBER,		// 描画する画像のID
			ScoreScript::Score_Screen_Number(2),	// 左上から見て何番目の位置の画像を表示するか
			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
			));

		//特定のメッセージを受信したら自信を殺すコンポーネントを追加
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_3_1
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto scoreScreen = std::make_shared<GameObject>();

		// ２次元座標
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(size, size),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
			SCORE_NUMBER,		// 描画する画像のID
			ScoreScript::Score_Screen_Number(3),	// 左上から見て何番目の位置の画像を表示するか
			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
			));

		//特定のメッセージを受信したら自信を殺すコンポーネントを追加
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_4_1
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto scoreScreen = std::make_shared<GameObject>();

		// ２次元座標
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(size, size),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
			SCORE_NUMBER,		// 描画する画像のID
			ScoreScript::Score_Screen_Number(4),	// 左上から見て何番目の位置の画像を表示するか
			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
			));

		//特定のメッセージを受信したら自信を殺すコンポーネントを追加
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_5_1
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto scoreScreen = std::make_shared<GameObject>();

		// ２次元座標
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(size, size),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
			SCORE_NUMBER,		// 描画する画像のID
			ScoreScript::Score_Screen_Number(5),	// 左上から見て何番目の位置の画像を表示するか
			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
			));

		//特定のメッセージを受信したら自信を殺すコンポーネントを追加
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_6_1
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto scoreScreen = std::make_shared<GameObject>();

		// ２次元座標
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(size, size),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
			SCORE_NUMBER,		// 描画する画像のID
			ScoreScript::Score_Screen_Number(6),	// 左上から見て何番目の位置の画像を表示するか
			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
			));

		//特定のメッセージを受信したら自信を殺すコンポーネントを追加
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_7_1
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto scoreScreen = std::make_shared<GameObject>();

		// ２次元座標
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(size, size),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
			SCORE_NUMBER,		// 描画する画像のID
			ScoreScript::Score_Screen_Number(7),	// 左上から見て何番目の位置の画像を表示するか
			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
			));

		//特定のメッセージを受信したら自信を殺すコンポーネントを追加
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_8_1
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto scoreScreen = std::make_shared<GameObject>();

		// ２次元座標
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(size, size),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
			SCORE_NUMBER,		// 描画する画像のID
			ScoreScript::Score_Screen_Number(8),	// 左上から見て何番目の位置の画像を表示するか
			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
			));

		//特定のメッセージを受信したら自信を殺すコンポーネントを追加
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(scoreScreen);
	}
};

struct Score_Screen_9_1
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto scoreScreen = std::make_shared<GameObject>();

		// ２次元座標
		scoreScreen->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(size, size),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		scoreScreen->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_UI,			// 描画するレイヤー
			SCORE_NUMBER,		// 描画する画像のID
			ScoreScript::Score_Screen_Number(9),	// 左上から見て何番目の位置の画像を表示するか
			Vector2(0.0f, 0.0f)		// 画像の中心（割合）
			));
		
		//特定のメッセージを受信したら自信を殺すコンポーネントを追加
		scoreScreen->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(scoreScreen);
	}
};


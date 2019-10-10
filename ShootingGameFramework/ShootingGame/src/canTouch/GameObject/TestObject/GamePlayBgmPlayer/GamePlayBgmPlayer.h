#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

struct GamePlayBgmPlayer
{
	static void create()
	{
		// ゲームオブジェクトを作成
		auto gamePlayBgmPlayer = std::make_shared<GameObject>();

		// BGM再生コンポーネントを追加
		gamePlayBgmPlayer->addComponent(std::make_shared<BgmPlayer>(
			TEST_BGM,	// BGMの種類
			true		// 直ぐに再生するか？
			));

		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
		gamePlayBgmPlayer->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(gamePlayBgmPlayer);
	}

	static void title()
	{
		// ゲームオブジェクトを作成
		auto gamePlayBgmPlayer = std::make_shared<GameObject>();

		// BGM再生コンポーネントを追加
		gamePlayBgmPlayer->addComponent(std::make_shared<BgmPlayer>(
			TITLE_BGM,	// 
			true		// 直ぐに再生するか？
			));

		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
		gamePlayBgmPlayer->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(gamePlayBgmPlayer);
	}

	static void game_1()
	{
		// ゲームオブジェクトを作成
		auto gamePlayBgmPlayer = std::make_shared<GameObject>();

		// BGM再生コンポーネントを追加
		gamePlayBgmPlayer->addComponent(std::make_shared<BgmPlayer>(
			GAME_BGM_1,	// 
			true		// 直ぐに再生するか？
			));

		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
		gamePlayBgmPlayer->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(gamePlayBgmPlayer);
	}

	static void game_2()
	{
		// ゲームオブジェクトを作成
		auto gamePlayBgmPlayer = std::make_shared<GameObject>();

		// BGM再生コンポーネントを追加
		gamePlayBgmPlayer->addComponent(std::make_shared<BgmPlayer>(
			GAME_BGM_2,	// 
			true		// 直ぐに再生するか？
			));

		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
		gamePlayBgmPlayer->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(gamePlayBgmPlayer);
	}

	static void game_3()
	{
		// ゲームオブジェクトを作成
		auto gamePlayBgmPlayer = std::make_shared<GameObject>();

		// BGM再生コンポーネントを追加
		gamePlayBgmPlayer->addComponent(std::make_shared<BgmPlayer>(
			GAME_BGM_3,	// 
			true		// 直ぐに再生するか？
			));

		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
		gamePlayBgmPlayer->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(gamePlayBgmPlayer);
	}
};
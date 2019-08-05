#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "GameEndCheckerScript.h"

struct GameEndChecker
{
	static void create()
	{
		// ゲームオブジェクトを作成
		auto gameEndChecker = std::make_shared<GameObject>();

		// ゲーム終了チェッカーのスクリプト
		gameEndChecker->addComponent(std::make_shared<GameEndCheckerScript>());

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(gameEndChecker);
	}
};
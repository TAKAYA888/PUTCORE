#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

struct GameOverBGM
{
	static void create()
	{
		//ゲームオブジェクトを作成
		auto gameOverBgm = std::make_shared<GameObject>();

		//BGMコンポーネントを追加
		gameOverBgm->addComponent(std::make_shared<BgmPlayer>(
			GAMEOVER_BGM,
			true
			));

		//特定のメッセージを受信したら自信を殺すコンポーネントを追加
		gameOverBgm->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_RESULT
			));

		//ゲームオブジェクトを追加
		GameObjectManager::addGameObject(gameOverBgm);
	}
};
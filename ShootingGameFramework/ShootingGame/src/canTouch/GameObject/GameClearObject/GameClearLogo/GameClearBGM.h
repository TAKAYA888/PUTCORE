#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

struct GameClearBGM
{
	static void create()
	{
		//ゲームオブジェクトを作成
		auto gameClearBgm = std::make_shared<GameObject>();

		//BGMコンポーネントを追加
		gameClearBgm->addComponent(std::make_shared<BgmPlayer>(
			GAMECLEAR_BGM,
			true
			));

		//特定のメッセージを受信したら自信を殺すコンポーネントを追加
		gameClearBgm->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_O_C
			));

		//ゲームオブジェクトを追加
		GameObjectManager::addGameObject(gameClearBgm);
	}
};
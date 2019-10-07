#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "EnemyGenerator2Script.h"

struct EnemyGenerator2
{
	static void create()
	{
		// ゲームオブジェクトを作成
		auto enemyGenerator2 = std::make_shared<GameObject>();

		// 使用する敵の出現情報のテキストファイルのパスを引数に敵出現コンポーネントを追加
		enemyGenerator2->addComponent(std::make_shared<EnemyGenerator2Script>(
			"res/text/stageData/stage2.txt"
			));

		// 特定のメッセージを受信したら自身を殺すコンポーネントを追加
		enemyGenerator2->addComponent(std::make_shared<ReceiveMessageToSelfDestroyer>(
			DIE_GAMEPLAY_OBJECT
			));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(enemyGenerator2);
	}
};
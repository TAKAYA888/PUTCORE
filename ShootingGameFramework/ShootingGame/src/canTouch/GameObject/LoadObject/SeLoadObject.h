#pragma once

#include <TktkIncludePaths.h>
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
#endif

// SEを読み込むゲームオブジェクト
struct SeLoadObject
{
	static void create(const std::string& loadFilePath)
	{
		// ゲームオブジェクトを作成
		auto seLoadObject = std::make_shared<GameObject>();

		// 作成したオブジェクトにSE読み込みコンポーネントを追加
		seLoadObject->addComponent(std::make_shared<SeLoader>(loadFilePath));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(seLoadObject);
	}
};
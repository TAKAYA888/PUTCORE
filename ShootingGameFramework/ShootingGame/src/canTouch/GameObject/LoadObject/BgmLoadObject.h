#pragma once

#include <TktkIncludePaths.h>
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
#endif

// BGMを読み込むゲームオブジェクト
struct BgmLoadObject
{
	static void create(const std::string& loadFilePath)
	{
		// ゲームオブジェクトを作成
		auto bgmLoadObject = std::make_shared<GameObject>();

		// 作成したオブジェクトにBGM読み込みコンポーネントを追加
		bgmLoadObject->addComponent(std::make_shared<BgmLoader>(loadFilePath));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(bgmLoadObject);
	}
};
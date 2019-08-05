#pragma once

#include <TktkIncludePaths.h>
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
#endif

// 画像を読み込むゲームオブジェクト
struct ImageLoadObject
{
	static void create(const std::string& loadFilePath)
	{
		// ゲームオブジェクトを作成
		auto imageLoadObject = std::make_shared<GameObject>();

		// 作成したオブジェクトに画像読み込みコンポーネントを追加
		imageLoadObject->addComponent(std::make_shared<TextureLoader>(loadFilePath));

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(imageLoadObject);
	}
};
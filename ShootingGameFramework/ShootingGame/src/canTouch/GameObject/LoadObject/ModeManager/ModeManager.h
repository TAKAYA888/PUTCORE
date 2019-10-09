#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "ModeManagerScript.h"

struct ModeManager
{
	static void create()
	{
		// ゲームオブジェクトを作成
		auto ModeManager = std::make_shared<GameObject>();

		// ２次元座標
		ModeManager->addComponent(std::make_shared<Transform2D>(
			Vector2::zero,				// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

	
		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(ModeManager);
	}
};
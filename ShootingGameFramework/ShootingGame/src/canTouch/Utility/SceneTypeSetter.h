#pragma once

#include <memory>
#include <TktkSceneManagement/SceneManager.h>
#include "../Enums/SceneType.h"
#include "../Scene/LoadScene.h"
#include "../Scene/TitleScene.h"
#include "../Scene/MainScene.h"

struct SceneTypeSetter
{
	static void set()
	{
		// シーンを追加する
		SceneManager::addScene(LOAD_SCENE, std::make_shared<LoadScene>());
		SceneManager::addScene(TITLE_SCENE, std::make_shared<TitleScene>());
		SceneManager::addScene(MAIN_SCENE, std::make_shared<MainScene>());

		// 初期シーンを設定する
		SceneManager::changeScene(LOAD_SCENE);
	}
};
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
		// �V�[����ǉ�����
		SceneManager::addScene(LOAD_SCENE, std::make_shared<LoadScene>());
		SceneManager::addScene(TITLE_SCENE, std::make_shared<TitleScene>());
		SceneManager::addScene(MAIN_SCENE, std::make_shared<MainScene>());

		// �����V�[����ݒ肷��
		SceneManager::changeScene(LOAD_SCENE);
	}
};
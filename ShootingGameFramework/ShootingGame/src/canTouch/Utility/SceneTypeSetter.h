#pragma once

#include <memory>
#include <TktkSceneManagement/SceneManager.h>
#include "../Enums/SceneType.h"
#include "../Scene/LoadScene.h"
#include "../Scene/TitleScene.h"
#include "../Scene/MainScene.h"
#include "../Scene/ClearScene.h"
#include "../Scene/GameOverScene.h"
#include "../Scene/ResultScene.h"
#include "../Scene/SelectStageScene.h"
#include "../Scene/Main2Scene.h"
#include "../Scene/Main3Scene.h"



struct SceneTypeSetter
{
	
	static void set()
	{
		// シーンを追加する
		SceneManager::addScene(LOAD_SCENE, std::make_shared<LoadScene>());
		SceneManager::addScene(TITLE_SCENE, std::make_shared<TitleScene>());
		SceneManager::addScene(MAIN_SCENE, std::make_shared<MainScene>());
		SceneManager::addScene(CLEAR_SCENE, std::make_shared<ClearScene>());
		SceneManager::addScene(GAMEOVER_SCENE, std::make_shared<GameOverScene>());
		SceneManager::addScene(RESULT_SCENE, std::make_shared<ResultScene>());
		SceneManager::addScene(STAGE_SELECT_SCENE, std::make_shared<SelectStageScene>());
		SceneManager::addScene(STAGE_TWO_SCENE, std::make_shared<Main2Scene>());
		SceneManager::addScene(STAGE_THREE_SCENE, std::make_shared<Main3Scene>());
		
        
		// 初期シーンを設定する
		SceneManager::changeScene(LOAD_SCENE);
	}
};
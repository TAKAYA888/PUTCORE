#include "GameOverScene.h"

#include "../GameObject/TestObject/Push_Space/Push_Space.h"
#include "../GameObject/GameOverObject/GameOverLogo/GameOverLogo.h"
#include"../GameObject//GameOverObject/GameOverLogo/GameOverBGM.h"

GameOverScene::GameOverScene()
{
}

void GameOverScene::start()
{
	GameOverLogo::create();
	Push_Space::create(Vector2(1280.0f / 2, 720.0f * 2 / 3));
	//BGM再生機を追加
	GameOverBGM::create();
}

void GameOverScene::update()
{
	if (Keyboard::getState(InputType::INPUT_ENDED, KeyboardKeyType::KEYBOARD_SPACE))
	{
		changeScene(RESULT_SCENE);
	}
}

void GameOverScene::end()
{
	// 全てのゲームオブジェクトに「DIE_TITLE_OBJECT」のメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_TITLE_OBJECT);
}

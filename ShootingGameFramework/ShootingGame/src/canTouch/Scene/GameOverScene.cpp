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
	Push_Space::create(Vector2(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2 + SCREEN_SIZE_Y / 4));
	//BGM再生機を追加
	GameOverBGM::create();
}

void GameOverScene::update()
{
	if (Keyboard::getState(InputType::INPUT_ENDED, KeyboardKeyType::KEYBOARD_SPACE) || GamePad::getState(GamePadNumber::GAME_PAD_NUMBER_1, InputType::INPUT_BEGIN, GamePadButtonType::GAME_PAD_B_BUTTON))
	{
		changeScene(RESULT_SCENE);
	}
}

void GameOverScene::end()
{
	// 全てのゲームオブジェクトに「DIE_TITLE_OBJECT」のメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_O_C);
}

#include "ClearScene.h"

#include "../GameObject/TestObject/Push_Space/Push_Space.h"
#include "../GameObject/GameClearObject/GameClearLogo/GameClearLogo.h"
#include"../GameObject/GameClearObject/GameClearLogo/GameClearBGM.h"

ClearScene::ClearScene()
{
}

void ClearScene::start()
{
	GameClearLogo::create();
	Push_Space::create(Vector2(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2 + SCREEN_SIZE_Y / 4));
	GameClearBGM::create();
}

void ClearScene::update()
{
	if (Keyboard::getState(InputType::INPUT_ENDED, KeyboardKeyType::KEYBOARD_SPACE) || GamePad::getState(GamePadNumber::GAME_PAD_NUMBER_1, InputType::INPUT_BEGIN, GamePadButtonType::GAME_PAD_B_BUTTON))
	{
		changeScene(RESULT_SCENE);
	}
}

void ClearScene::end()
{
	// 全てのゲームオブジェクトに「DIE_TITLE_OBJECT」のメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_O_C);
}

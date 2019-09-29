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
	Push_Space::create(Vector2(1280.0f / 2, 720.0f * 2 / 3));
	GameClearBGM::create();
}

void ClearScene::update()
{
	if (Keyboard::getState(InputType::INPUT_ENDED, KeyboardKeyType::KEYBOARD_SPACE))
	{
		changeScene(RESULT_SCENE);
	}
}

void ClearScene::end()
{
	// 全てのゲームオブジェクトに「DIE_TITLE_OBJECT」のメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_O_C);
}

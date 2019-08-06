#include "ClearScene.h"

#include "../GameObject/GameClearObject/GameClearLogo/GameClearLogo.h"

ClearScene::ClearScene()
{
}

void ClearScene::start()
{
	GameClearLogo::create();
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
	// �S�ẴQ�[���I�u�W�F�N�g�ɁuDIE_TITLE_OBJECT�v�̃��b�Z�[�W���΂�
	GameObjectManager::sendMessage(DIE_TITLE_OBJECT);
}

#include "ResultScene.h"

#include "../GameObject/ResultObject/ResultLogo/ResultLogo.h"

ResultScene::ResultScene()
{
}

void ResultScene::start()
{
	ResultLogo::create();
}

void ResultScene::update()
{
	if (Keyboard::getState(InputType::INPUT_ENDED, KeyboardKeyType::KEYBOARD_SPACE))
	{
		changeScene(TITLE_SCENE);
	}
}

void ResultScene::end()
{
	// �S�ẴQ�[���I�u�W�F�N�g�ɁuDIE_TITLE_OBJECT�v�̃��b�Z�[�W���΂�
	GameObjectManager::sendMessage(DIE_TITLE_OBJECT);
}

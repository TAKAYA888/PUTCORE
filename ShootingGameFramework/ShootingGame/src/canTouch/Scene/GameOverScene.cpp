#include "GameOverScene.h"

#include "../GameObject/TestObject/Push_Space/Push_Space.h"
#include "../GameObject/GameOverObject/GameOverLogo/GameOverLogo.h"

GameOverScene::GameOverScene()
{
}

void GameOverScene::start()
{
	GameOverLogo::create();
	Push_Space::create(Vector2(1280.0f / 2, 720.0f * 2 / 3));
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
	// �S�ẴQ�[���I�u�W�F�N�g�ɁuDIE_TITLE_OBJECT�v�̃��b�Z�[�W���΂�
	GameObjectManager::sendMessage(DIE_TITLE_OBJECT);
}

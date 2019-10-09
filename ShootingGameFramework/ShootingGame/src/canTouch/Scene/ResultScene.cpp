#include "ResultScene.h"

#include "../GameObject/ResultObject/ResultLogo/ResultLogo.h"
#include "../GameObject/ResultObject/Score_Screen_result/Score_Screen_result.h"

#include "../Utility/ScreenSize.h"

ResultScene::ResultScene()
{
}

void ResultScene::start()
{
	ResultLogo::create();

	float Complement = 60.0f; // �����Ԃ̌���

	float x = SCREEN_SIZE_X / 4 + SCREEN_SIZE_X / 14;
	float y = SCREEN_SIZE_Y / 2 + SCREEN_SIZE_Y / 100;

	float Crack = 128.0f / 10.0f + Complement;

	Score_Screen_1_1::create(Vector2(x, y));
	x += Crack;
	Score_Screen_2_1::create(Vector2(x, y));
	x += Crack;
	Score_Screen_3_1::create(Vector2(x, y));
	x += Crack;
	Score_Screen_4_1::create(Vector2(x, y));
	x += Crack;
	Score_Screen_5_1::create(Vector2(x, y));
	x += Crack;
	Score_Screen_6_1::create(Vector2(x, y));
	x += Crack;
	Score_Screen_7_1::create(Vector2(x, y));
	x += Crack;
	Score_Screen_8_1::create(Vector2(x, y));
	x += Crack;
	Score_Screen_9_1::create(Vector2(x, y));
}

void ResultScene::update()
{
	if (Keyboard::getState(InputType::INPUT_ENDED, KeyboardKeyType::KEYBOARD_SPACE) || GamePad::getState(GamePadNumber::GAME_PAD_NUMBER_1, InputType::INPUT_BEGIN, GamePadButtonType::GAME_PAD_B_BUTTON))
	{
		changeScene(TITLE_SCENE);
	}
}

void ResultScene::end()
{
	// �S�ẴQ�[���I�u�W�F�N�g�ɁuDIE_TITLE_OBJECT�v�̃��b�Z�[�W���΂�
	GameObjectManager::sendMessage(DIE_RESULT);
}

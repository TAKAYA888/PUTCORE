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

	float Complement = 60.0f; // 数字間の隙間

	float x = 300.0f - 5.0f;
	float y = SCREEN_SIZE_Y / 2 - 40.0f;

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
	if (Keyboard::getState(InputType::INPUT_ENDED, KeyboardKeyType::KEYBOARD_SPACE))
	{
		changeScene(TITLE_SCENE);
	}
}

void ResultScene::end()
{
	// 全てのゲームオブジェクトに「DIE_TITLE_OBJECT」のメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_RESULT);
}

#include "Push_SpaceScript.h"

Push_SpaceScript::Push_SpaceScript()
{
}

void Push_SpaceScript::update()
{
	if (counter < 0)
	{
		if (getComponent<Sprite2dDrawer>().lock()->isActive() == true)
		{
			getComponent<Sprite2dDrawer>().lock()->setActive(false);
		}
		else
		{
			getComponent<Sprite2dDrawer>().lock()->setActive(true);
		}
		counter = 0.5;
	}
	else
	{
		counter -= TktkTime::deltaTime();
	}

	//SPACEキーを押すとSEが流れる
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_SPACE) || GamePad::getState(GamePadNumber::GAME_PAD_NUMBER_1, InputType::INPUT_BEGIN, GamePadButtonType::GAME_PAD_B_BUTTON))
	{
		getComponent<SePlayer>().lock()->playSe();
	}
}

void Push_SpaceScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_O_C)
	{
		getGameObject().lock()->destroy();
	}
}


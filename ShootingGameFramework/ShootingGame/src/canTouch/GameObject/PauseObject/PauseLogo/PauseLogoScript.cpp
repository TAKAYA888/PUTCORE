#include "PauseLogoScript.h"

PauseLogoScript::PauseLogoScript()
{
}

void PauseLogoScript::update()
{
	if (count % 2 == 0)
	{
		getComponent<Sprite2dDrawer>().lock()->setActive(false);
	}
	else if (count % 2 == 1)
	{
		getComponent<Sprite2dDrawer>().lock()->setActive(true);
	}

	if (Keyboard::getState(InputType::INPUT_ENDED, KeyboardKeyType::KEYBOARD_TAB))
	{
		count = count + 1;
	}

}

void PauseLogoScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

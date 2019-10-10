#include "PauseLogoScript.h"

PauseLogoScript::PauseLogoScript()
{
}

void PauseLogoScript::update()
{
}

void PauseLogoScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == PAUSE_END)
	{
		getGameObject().lock()->destroy();
	}
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

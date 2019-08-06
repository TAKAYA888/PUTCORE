#include "GameOverLogoScript.h"

GameOverLogoScript::GameOverLogoScript()
{
}

void GameOverLogoScript::update()
{
}

void GameOverLogoScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

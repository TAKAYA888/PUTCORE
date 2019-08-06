#include "GameClearLogoScript.h"

GameClearLogoScript::GameClearLogoScript()
{
}

void GameClearLogoScript::update()
{
}

void GameClearLogoScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

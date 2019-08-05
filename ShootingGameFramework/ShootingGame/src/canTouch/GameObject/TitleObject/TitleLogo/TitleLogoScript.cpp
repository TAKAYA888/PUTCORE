#include "TitleLogoScript.h"

TitleLogoScript::TitleLogoScript()
{
}

void TitleLogoScript::update()
{
}

void TitleLogoScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

#include "ResultLogoScript.h"

ResultLogoScript::ResultLogoScript()
{
}

void ResultLogoScript::update()
{
}

void ResultLogoScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

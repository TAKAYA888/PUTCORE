#include "BackGround_1Script.h"

BackGround_1Script::BackGround_1Script()
{
}

void BackGround_1Script::update()
{
}

void BackGround_1Script::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

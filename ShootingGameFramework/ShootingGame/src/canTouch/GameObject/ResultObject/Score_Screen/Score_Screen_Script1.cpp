#include "Score_Screen_Script1.h"

Score_Screen_Script1::Score_Screen_Script1()
{
}

void Score_Screen_Script1::update()
{
}

void Score_Screen_Script1::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_RESULT)
	{
		//getGameObject().lock()->destroy();
	}
}
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
}

void Push_SpaceScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}


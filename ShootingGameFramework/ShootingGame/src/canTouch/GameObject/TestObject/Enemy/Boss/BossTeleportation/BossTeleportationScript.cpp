#include "BossTeleportationScript.h"

BossTeleportationScript::BossTeleportationScript()
{
	timer = 0;
}

void BossTeleportationScript::start()
{
}

void BossTeleportationScript::update()
{
	//�J�E���g�A�b�v
	timer += TktkTime::deltaTime();

	if (timer > 0.2f)
	{
		getGameObject().lock()->destroy();
	}
}

void BossTeleportationScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
}

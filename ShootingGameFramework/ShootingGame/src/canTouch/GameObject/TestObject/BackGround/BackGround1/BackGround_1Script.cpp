#include "BackGround_1Script.h"

BackGround_1Script::BackGround_1Script()
{
	timer = 0;
}

void BackGround_1Script::update()
{
	timer = TktkTime::deltaTime() * 60.0f*3.0f;
	Vector2 nowPosition = getComponent<Transform2D>().lock()->getWorldPosition();
	if (nowPosition.x >= SCREEN_SIZE_X * -1.0f + 3.0f)
	{
		getComponent<Transform2D>().lock()->setLocalPosition(Vector2(nowPosition.x - timer, nowPosition.y + 0));
	}
	else
	{
		getComponent<Transform2D>().lock()->setLocalPosition(Vector2(SCREEN_SIZE_X, 0));
	}
}

void BackGround_1Script::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

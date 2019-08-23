#include "setCoreScript.h"

#include "../StayCore/CoreScript.h"
#include "../../../TestObject/PlayerBullet/PlayerBullet.h"
#include "../../../TestObject/CoreBullet/CoreBullet.h"

setCoreScript::setCoreScript()
{
	counter = 0;
	coolTime = 0.2f;
}

void setCoreScript::update()
{
	bool curActiveFlag = getComponent<CoreScript>().lock()->isActive();

	Vector2 Postion = getComponent<Transform2D>().lock()->getWorldPosition();

	counter += TktkTime::deltaTime();

	if (curActiveFlag == true)
	{
		getComponent<setCoreScript>().lock()->setActive(false);
	}

	if (coolTime < 0)
	{
		// ’e‚Ì‰Šú‘¬“x
		auto initVelocity1 = Vector2(MathHelper::sin(90), -MathHelper::cos(90)) * 512.0f;
		auto initVelocity2 = Vector2(MathHelper::sin(70), -MathHelper::cos(70)) * 512.0f;
		auto initVelocity3 = Vector2(MathHelper::sin(110), -MathHelper::cos(110)) * 512.0f;
		CoreBullet::create(Postion, initVelocity1);
		CoreBullet::create(Postion, initVelocity2);
		CoreBullet::create(Postion, initVelocity3);

		coolTime += 0.2f;
	}
	else
	{
		coolTime -= TktkTime::deltaTime();
	}

	if (counter >= 10)
	{
		getComponent<CoreScript>().lock()->setActive(true);
		counter = 0;
	}
}

void setCoreScript::onCollisionEnter(GameObjectPtr other)
{
}

void setCoreScript::onCollisionStay(GameObjectPtr other)
{
}

void setCoreScript::onCollisionExit(GameObjectPtr other)
{
}

void setCoreScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

void setCoreScript::inputToMove()
{
}

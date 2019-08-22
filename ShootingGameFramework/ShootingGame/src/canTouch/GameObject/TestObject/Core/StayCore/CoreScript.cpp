#include "CoreScript.h"

#include "../setCore/setCoreScript.h"

CoreScript::CoreScript()
{
	CoreCoolTime = 10;
}

void CoreScript::update()
{
	Vector2 playerPostion = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();
	Vector2 setPosition;
	setPosition.x = playerPostion.x;
	setPosition.y = playerPostion.y + 68;
	getComponent<Transform2D>().lock()->setLocalPosition(setPosition);


	if (Keyboard::getState(InputType::INPUT_BEGIN, KeyboardKeyType::KEYBOARD_X) && CoreCoolTime < 0)
	{
		getComponent<setCoreScript>().lock()->setActive(true);
		getComponent<CoreScript>().lock()->setActive(false);
		CoreCoolTime = 10;
	}
	else
	{
		CoreCoolTime -= TktkTime::deltaTime();
	}


}

void CoreScript::onCollisionEnter(GameObjectPtr other)
{
}

void CoreScript::onCollisionStay(GameObjectPtr other)
{
}

void CoreScript::onCollisionExit(GameObjectPtr other)
{
}

void CoreScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

void CoreScript::inputToMove()
{
}
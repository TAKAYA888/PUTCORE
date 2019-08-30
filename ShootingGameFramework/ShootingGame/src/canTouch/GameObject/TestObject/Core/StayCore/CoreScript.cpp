#include "CoreScript.h"

#include "../setCore/setCoreScript.h"

CoreScript::CoreScript()
{
	CoreCoolTime = 10;
	DrawTime = 0;
}

void CoreScript::update()
{
	Vector2 playerPostion = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();
	Vector2 setPosition;
	setPosition.x = playerPostion.x;
	setPosition.y = playerPostion.y + 40;
	getComponent<Transform2D>().lock()->setLocalPosition(setPosition);

	//ìñÇΩÇËîªíËÇè¡Ç∑
	getComponent<RectCollider>().lock()->setActive(false);
	//ìñÇΩÇËîªíËÇï`âÊïtÇØÇÈ
	getComponent<RectColliderWireFrameDrawer>().lock()->setActive(false);

	if (Keyboard::getState(InputType::INPUT_BEGIN, KeyboardKeyType::KEYBOARD_X) && CoreCoolTime < 0)
	{
		getComponent<setCoreScript>().lock()->setActive(true);
		getComponent<CoreScript>().lock()->setActive(false);
		CoreCoolTime = 10.5f;
		DrawTime = 0;
	}
	else
	{
		CoreCoolTime -= TktkTime::deltaTime();
	}

	if (DrawTime <= 10)
	{
		DrawTime += TktkTime::deltaTime();
		getComponent<AnimatedSprite2d>().lock()->setAnimSpeedRate(1);
	}
	else if(DrawTime >10)
	{
		getComponent<AnimatedSprite2d>().lock()->setAnimSpeedRate(0);
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
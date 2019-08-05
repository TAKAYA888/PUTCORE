#include "TitleCursorScript.h"


TitleCursorScript::TitleCursorScript()
{
}

void TitleCursorScript::update()
{
	auto mousePos = Mouse::getCursorPoint();

	getComponent<Transform2D>().lock()->setLocalPosition(mousePos);
}

void TitleCursorScript::onCollisionEnter(GameObjectPtr other)
{
}

void TitleCursorScript::onCollisionStay(GameObjectPtr other)
{
}

void TitleCursorScript::onCollisionExit(GameObjectPtr other)
{
}

void TitleCursorScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

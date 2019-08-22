#include "CoreBulletScript.h"

CoreBulletScript::CoreBulletScript()
{
}

void CoreBulletScript::update()
{
}

void CoreBulletScript::onCollisionEnter(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_ENEMY」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY)
	{
		// 自分を殺す
		getGameObject().lock()->destroy();
	}

	// 衝突相手のタグが「GAME_OBJECT_TAG_ENEMY_BOSS」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY_BOSS)
	{
		// 自分を殺す
		getGameObject().lock()->destroy();
	}
}

void CoreBulletScript::onCollisionStay(GameObjectPtr other)
{
}

void CoreBulletScript::onCollisionExit(GameObjectPtr other)
{
}

void CoreBulletScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}
#include "CorePowerupItemScript.h"

#include "../../Explosion_Enemy/Explosion_Enemy.h"

CorePowerupItemScript::CorePowerupItemScript()
{
}

//毎フレーム呼ばれる
void CorePowerupItemScript::update()
{
}

//衝突開始で呼ばれる
void CorePowerupItemScript::onCollisionEnter(GameObjectPtr other)
{
	// 衝突相手のタグが「プレイヤー」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER)
	{
		getComponent<SePlayer>().lock()->playSe();
		// 自分を殺す
		getGameObject().lock()->destroy();
	}
}

// 衝突中で呼ばれる
void CorePowerupItemScript::onCollisionStay(GameObjectPtr other)
{
}

// 衝突終了で呼ばれる
void CorePowerupItemScript::onCollisionExit(GameObjectPtr other)
{
}

void CorePowerupItemScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}


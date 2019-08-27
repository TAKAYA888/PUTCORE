#include "VirusEnemyBulletScript.h"

VirusEnemyBulletScript::VirusEnemyBulletScript()
{
}

// 毎フレーム呼ばれる
void VirusEnemyBulletScript::update()
{
}

// 衝突開始で呼ばれる
void VirusEnemyBulletScript::onCollisionEnter(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_PLAYER」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER)
	{
		// 自分を殺す
		getGameObject().lock()->destroy();
	}
}

// 衝突中で呼ばれる
void VirusEnemyBulletScript::onCollisionStay(GameObjectPtr other)
{
}

// 衝突終了で呼ばれる
void VirusEnemyBulletScript::onCollisionExit(GameObjectPtr other)
{
}

void VirusEnemyBulletScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}
#include "PlayerBulletScript.h"

PlayerBulletScript::PlayerBulletScript()
{
}

// 毎フレーム呼ばれる
void PlayerBulletScript::update()
{
}

// 衝突開始で呼ばれる
void PlayerBulletScript::onCollisionEnter(GameObjectPtr other)
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

// 衝突中で呼ばれる
void PlayerBulletScript::onCollisionStay(GameObjectPtr other)
{
}

// 衝突終了で呼ばれる
void PlayerBulletScript::onCollisionExit(GameObjectPtr other)
{
}

void PlayerBulletScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

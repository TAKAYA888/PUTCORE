#include "CoreBulletScript.h"

CoreBulletScript::CoreBulletScript()
{
}

void CoreBulletScript::update()
{
}

void CoreBulletScript::onCollisionEnter(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_ENEMY�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY)
	{
		// �������E��
		getGameObject().lock()->destroy();
	}

	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_ENEMY_BOSS�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY_BOSS)
	{
		// �������E��
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
#include "EnemyNormalBulletScript.h"

EnemyNormalBulletScript::EnemyNormalBulletScript()
{
}

// ���t���[���Ă΂��
void EnemyNormalBulletScript::update()
{
}

// �ՓˊJ�n�ŌĂ΂��
void EnemyNormalBulletScript::onCollisionEnter(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_PLAYER�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER)
	{
		// �������E��
		getGameObject().lock()->destroy();
	}
}

// �Փ˒��ŌĂ΂��
void EnemyNormalBulletScript::onCollisionStay(GameObjectPtr other)
{
}

// �ՓˏI���ŌĂ΂��
void EnemyNormalBulletScript::onCollisionExit(GameObjectPtr other)
{
}

void EnemyNormalBulletScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

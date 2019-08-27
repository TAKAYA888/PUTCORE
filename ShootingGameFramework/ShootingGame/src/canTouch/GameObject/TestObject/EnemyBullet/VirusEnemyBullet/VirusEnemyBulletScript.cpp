#include "VirusEnemyBulletScript.h"

VirusEnemyBulletScript::VirusEnemyBulletScript()
{
}

// ���t���[���Ă΂��
void VirusEnemyBulletScript::update()
{
}

// �ՓˊJ�n�ŌĂ΂��
void VirusEnemyBulletScript::onCollisionEnter(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_PLAYER�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER)
	{
		// �������E��
		getGameObject().lock()->destroy();
	}
}

// �Փ˒��ŌĂ΂��
void VirusEnemyBulletScript::onCollisionStay(GameObjectPtr other)
{
}

// �ՓˏI���ŌĂ΂��
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
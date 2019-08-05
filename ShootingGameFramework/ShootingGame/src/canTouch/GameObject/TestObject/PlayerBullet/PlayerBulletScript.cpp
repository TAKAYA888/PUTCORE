#include "PlayerBulletScript.h"

PlayerBulletScript::PlayerBulletScript()
{
}

// ���t���[���Ă΂��
void PlayerBulletScript::update()
{
}

// �ՓˊJ�n�ŌĂ΂��
void PlayerBulletScript::onCollisionEnter(GameObjectPtr other)
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

// �Փ˒��ŌĂ΂��
void PlayerBulletScript::onCollisionStay(GameObjectPtr other)
{
}

// �ՓˏI���ŌĂ΂��
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

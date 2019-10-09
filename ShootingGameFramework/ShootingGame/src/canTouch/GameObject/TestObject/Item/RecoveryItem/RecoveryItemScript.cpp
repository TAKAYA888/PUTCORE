#include "RecoveryItemScript.h"

#include "../../Explosion_Enemy/Explosion_Enemy.h"

RecoveryItemScript::RecoveryItemScript()
{
}

//���t���[���Ă΂��
void RecoveryItemScript::update()
{
}

//�ՓˊJ�n�ŌĂ΂��
void RecoveryItemScript::onCollisionEnter(GameObjectPtr other)
{
	// �Փˑ���̃^�O���u�v���C���[�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER)
	{
		getComponent<SePlayer>().lock()->playSe();
		// �������E��
		getGameObject().lock()->destroy();
	}
}

// �Փ˒��ŌĂ΂��
void RecoveryItemScript::onCollisionStay(GameObjectPtr other)
{
}

// �ՓˏI���ŌĂ΂��
void RecoveryItemScript::onCollisionExit(GameObjectPtr other)
{
}

void RecoveryItemScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

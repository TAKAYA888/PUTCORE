#include "CorePowerupItemScript.h"

#include "../../Explosion_Enemy/Explosion_Enemy.h"

CorePowerupItemScript::CorePowerupItemScript()
{
}

//���t���[���Ă΂��
void CorePowerupItemScript::update()
{
}

//�ՓˊJ�n�ŌĂ΂��
void CorePowerupItemScript::onCollisionEnter(GameObjectPtr other)
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
void CorePowerupItemScript::onCollisionStay(GameObjectPtr other)
{
}

// �ՓˏI���ŌĂ΂��
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


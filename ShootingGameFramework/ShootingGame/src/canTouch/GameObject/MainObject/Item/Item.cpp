#include "ItemScript.h"

ItemScript::ItemScript()
{
}

// ���t���[���Ă΂��
void ItemScript::update()
{
	// �ړ�
	move();
	
	

	// �̗͂��O�ȉ��ɂȂ�����
	if (m_hp <= 0)
	{
		getComponent<SePlayer>().lock()->playSe();
		// �������E��
		getGameObject().lock()->destroy();
	}
}

// �ՓˊJ�n�ŌĂ΂��
void ItemScript::onCollisionEnter(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_PLAYER_BULLET�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER_BULLET)
	{
	
	

		// �̗͂�-1����
		m_hp--;
	}
}

// �Փ˒��ŌĂ΂��
void ItemScript::onCollisionStay(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_PLAYER�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER)
	{
		
		// �̗͂�-1����
		m_hp--;
	}
}

// �ՓˏI���ŌĂ΂��
void ItemScript::onCollisionExit(GameObjectPtr other)
{
}

void ItemScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

// �ړ�
void ItemScript::move()
{
	// ���g�̉�]�p�x
	float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

	// �ړ����x�{����
	auto velocity = Vector2(MathHelper::sin(rotationDeg), -MathHelper::cos(rotationDeg)) * 20.0f;


	// �ړ�����
	getComponent<InertialMovement2D>().lock()->addForce(velocity);
}



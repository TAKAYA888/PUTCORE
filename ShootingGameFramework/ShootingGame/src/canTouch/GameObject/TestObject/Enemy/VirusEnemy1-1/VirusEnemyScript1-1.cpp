#include "VirusEnemyScript1-1.h"

#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "VirusEnemy1-1.h"

VirusEnemyScript1_1::VirusEnemyScript1_1()
{
	timer = 0;
}

//���t���[���Ă΂�Ă�
void VirusEnemyScript1_1::update()
{
	timer += TktkTime::deltaTime();

	//�ړ�
	move();

	//�̗͂�0�ȉ��ɂȂ�����
	if (m_hp <= 0)
	{
		getGameObject().lock()->destroy();
	}
}

//�Ռ��J�n�ŌĂ΂��
void VirusEnemyScript1_1::onCollisionEnter(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_PLAYER_BULLET�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER_BULLET || other.lock()->getTag() == GAME_OBJECT_TAG_CORE_BULLET)
	{
		// �����𐶐�����
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// �̗͂�-1����
		m_hp--;
	}
}

//�Փ˒��ŌĂ΂��
void VirusEnemyScript1_1::onCollisionStay(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_PLAYER�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER || other.lock()->getTag() == GAME_OBJECT_TAG_CORE_BULLET)
	{
		// �����𐶐�����
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// �̗͂�-1����
		m_hp--;
	}
}

//�ՓˏI���ŌĂ΂��
void VirusEnemyScript1_1::onCollisionExit(GameObjectPtr other)
{
}

void VirusEnemyScript1_1::handleMessage(int  eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

//�ړ�
void VirusEnemyScript1_1::move()
{
	// ���g�̉�]�p�x
	float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

	if (timer < 2.5f)
	{
		//�v�����i�[�A�Ō�̐��A�ύX�\
		auto velocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 15.0f;

		// �ړ�����
		getComponent<InertialMovement2D>().lock()->addForce(velocity);
	}
	else if (timer < 5.3f)
	{
		auto velocity = Vector2(MathHelper::sin(420), MathHelper::cos(420)) * 15.0f;

		// �ړ�����
		getComponent<InertialMovement2D>().lock()->addForce(velocity);
	}
	else
	{
		auto velocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 15.0f;

		// �ړ�����
		getComponent<InertialMovement2D>().lock()->addForce(velocity);
	}
}
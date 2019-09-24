#include "VirusEnemyScript4.h"

#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "VirusEnemy4.h"

VirusEnemyScript4::VirusEnemyScript4()
{
	timer = 0;
}

//���t���[���Ă΂�Ă�
void VirusEnemyScript4::update()
{
	timer += TktkTime::deltaTime();

	//�ړ�
	move();

	//�̗͂�0�ȉ��ɂȂ�����
	if (m_hp <= 0)
	{
		GameObjectManager::sendMessage(DIE_Enemy4);
		getGameObject().lock()->destroy();
	}
}

//�Ռ��J�n�ŌĂ΂��
void VirusEnemyScript4::onCollisionEnter(GameObjectPtr other)
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
void VirusEnemyScript4::onCollisionStay(GameObjectPtr other)
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
void VirusEnemyScript4::onCollisionExit(GameObjectPtr other)
{
}

void VirusEnemyScript4::handleMessage(int  eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

//�ړ�
void VirusEnemyScript4::move()
{
	// ���g�̉�]�p�x
	float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

	if (timer < 0.5f)
	{
		//�v�����i�[�A�Ō�̐��A�ύX�\
		auto velocity = Vector2(MathHelper::sin(345), MathHelper::cos(0)) * 50.0f;

		// �ړ�����
		getComponent<InertialMovement2D>().lock()->addForce(velocity);
	}
	else if (timer < 1.01f)
	{
		//�v�����i�[�A�Ō�̐��A�ύX�\
		auto velocity = Vector2(MathHelper::sin(195), MathHelper::cos(195)) * 50.0f;

		// �ړ�����
		getComponent<InertialMovement2D>().lock()->addForce(velocity);
	}
	else
	{
		timer = 0;
	}
}
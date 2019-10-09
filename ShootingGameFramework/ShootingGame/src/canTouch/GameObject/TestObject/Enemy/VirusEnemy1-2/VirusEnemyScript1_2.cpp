#include "VirusEnemyScript1-2.h"

#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "VirusEnemy1-2.h"
#include "../../Item/CorePowerupItem/CorePowerupItem.h"
#include "../../Item/RecoveryItem/RecoveryItem.h"
#include "../../Player/PlayerScript.h"

VirusEnemyScript1_2::VirusEnemyScript1_2()
{
	timer = 0;
	add_core_bullet = 0;
	counter = 0;
	playerFrag = true;
}

//���t���[���Ă΂��
void VirusEnemyScript1_2::update()
{
	auto player = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER);

	if (playerFrag)
	{
		add_core_bullet = player.lock()->getComponent<PlayerScript>().lock()->add_core_bullet;
	}

	timer += TktkTime::deltaTime();

	Random::randomize();

	//�ړ�
	move();

	//�̗͂�0�ȉ��ɂȂ�����
	if (m_hp <= 0)
	{
		counter = Random::getRandI(0, 10);

		if (0 <= counter && counter < 2)
		{
			//`�p���[�A�b�v�A�C�e��
			PowerupItem();
		}
		else
		{
			//�񕜃A�C�e��
			RecoveryItem();
		}

		GameObjectManager::sendMessage(DIE_Enemy1_2);
		getGameObject().lock()->destroy();
	}
}

//�ՓˊJ�n�ŌĂ΂��
void VirusEnemyScript1_2::onCollisionEnter(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_PLAYER_BULLET�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER_BULLET)
	{
		// �����𐶐�����
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// �̗͂�-1����
		m_hp--;
	}

	if (other.lock()->getTag() == GAME_OBJECT_TAG_CORE_BULLET)
	{
		// �����𐶐�����
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		//�̗͂�-3�ȏシ��
		m_hp = m_hp - add_core_bullet;
	}
}

//�Փ˒��ŌĂ΂��
void VirusEnemyScript1_2::onCollisionStay(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_PLAYER�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER)
	{
		// �����𐶐�����
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// �̗͂�-1����
		m_hp--;
	}

	if (other.lock()->getTag() == GAME_OBJECT_TAG_CORE_BULLET)
	{
		// �����𐶐�����
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		//�̗͂�-3����
		m_hp = m_hp - add_core_bullet;
	}
}

//�ՓˏI���ŌĂ΂�܂�
void VirusEnemyScript1_2::onCollisionExit(GameObjectPtr other)
{
}

void VirusEnemyScript1_2::handleMessage(int  eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}

	if (eventMessageType == DIE_PLAYER)
	{
		playerFrag = false;
	}
}
//�ړ�
void VirusEnemyScript1_2::move()
{
	// ���g�̉�]�p�x
	float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

	if (timer < 3.5f)
	{
		//�v�����i�[�A�Ō�̐��A�ύX�\
		auto velocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 15.0f;

		// �ړ�����
		getComponent<InertialMovement2D>().lock()->addForce(velocity);
	}
	else if (timer < 7.3f)
	{
		auto velocity = Vector2(MathHelper::sin(120), MathHelper::cos(120)) * 15.0f;

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

void VirusEnemyScript1_2::PowerupItem()
{
	auto PowerupItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// �ړ����x�{����
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 20.0f;

	//�p���[�A�b�v�A�C�e��
	CorePowerupItem::create(PowerupItemPos, inivelocity);
}

void VirusEnemyScript1_2::RecoveryItem()
{
	auto RecoveryItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// �ړ����x�{����
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 20.0f;

	RecoveryItem::create(RecoveryItemPos, inivelocity);
}

#include "VirusEnemyScript4.h"

#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "VirusEnemy4.h"
#include "../../Item/CorePowerupItem/CorePowerupItem.h"
#include "../../Player/PlayerScript.h"

VirusEnemyScript4::VirusEnemyScript4()
{
	timer = 0;

	add_core_bullet = 0;
}

//���t���[���Ă΂�Ă�
void VirusEnemyScript4::update()
{
	auto player = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER);

	add_core_bullet = player.lock()->getComponent<PlayerScript>().lock()->add_core_bullet;

	timer += TktkTime::deltaTime();

	//�ړ�
	move();

	//�̗͂�0�ȉ��ɂȂ�����
	if (m_hp <= 0)
	{
		PowerupItem();

		GameObjectManager::sendMessage(DIE_Enemy4);
		getGameObject().lock()->destroy();
	}
}

//�Ռ��J�n�ŌĂ΂��
void VirusEnemyScript4::onCollisionEnter(GameObjectPtr other)
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

		//�̗͂�-3����
		m_hp = m_hp - add_core_bullet;
	}
}

//�Փ˒��ŌĂ΂��
void VirusEnemyScript4::onCollisionStay(GameObjectPtr other)
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

void VirusEnemyScript4::PowerupItem()
{
	auto PowerupItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// �ړ����x�{����
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 20.0f;

	//�p���[�A�b�v�A�C�e��
	CorePowerupItem::create(PowerupItemPos, inivelocity);
}

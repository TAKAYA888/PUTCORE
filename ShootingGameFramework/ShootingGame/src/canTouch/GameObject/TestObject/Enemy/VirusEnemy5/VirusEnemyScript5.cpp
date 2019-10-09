#include "VirusEnemyScript5.h"

#include "../../EnemyBullet/VirusEnemyBullet/VirusEnemyBullet.h"
#include "../../Explosion/Explosion.h"
#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "../../Item/CorePowerupItem/CorePowerupItem.h"
#include "../../Player/PlayerScript.h"
#include "../../Item/RecoveryItem/RecoveryItem.h"

VirusEnemyScript5::VirusEnemyScript5()
{
	timer = 0;

	add_core_bullet = 0;

	counter = 0;

	playerFrag = true;
}

//���t���[���Ă΂��
void VirusEnemyScript5::update()
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

		GameObjectManager::sendMessage(DIE_Enemy5);
		getGameObject().lock()->destroy();
	}
}

// �ՓˊJ�n�ŌĂ΂��
void VirusEnemyScript5::onCollisionEnter(GameObjectPtr other)
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
void VirusEnemyScript5::onCollisionStay(GameObjectPtr other)
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

		//�̗͂�-3�ȏシ��
		m_hp = m_hp - add_core_bullet;
	}
}

//�ՓˏI���ŌĂ΂��
void VirusEnemyScript5::onCollisionExit(GameObjectPtr other)
{
}

void VirusEnemyScript5::handleMessage(int  eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
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
void VirusEnemyScript5::move()
{
	if (timer < 0.7f)
	{
		// ���g�̉�]�p�x
		float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

		// �ړ����x�{����
		auto velocity = Vector2(MathHelper::sin(rotationDeg), -MathHelper::cos(rotationDeg)) * 15.0f;

		// �ړ�����
		getComponent<InertialMovement2D>().lock()->addForce(velocity);
	}
	else if (timer <= 5.7f)
	{
		//�e�𔭎�
		shot();
	}
	else
	{
		// ���g�̉�]�p�x
		float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

		// �ړ����x�{����
		auto velocity = Vector2(MathHelper::sin(rotationDeg), -MathHelper::cos(rotationDeg)) * 15.0f;

		// �ړ�����
		getComponent<InertialMovement2D>().lock()->addForce(velocity);
	}
}

//�e�𔭎�
void VirusEnemyScript5::shot()
{
	// �e���˃^�C�}�[���X�V
	m_shotTimer += TktkTime::deltaTime();

	// �e���˃^�C�}�[�����ˎ��ԂɂȂ�����
	if (m_shotTimer > m_shotInterval)
	{
		// �e�̏o�����W
		auto spawnPos = getComponent<Transform2D>().lock()->getWorldPosition();

		// �v���C���[�̈ʒu���擾
		Vector2 playerPos = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();

		// ���g�̉�]�p�x
		float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

		// �u�v���C���[�v->�u�G�l�~�[�v�̃x�N�g�������߂�
		auto enemyToMouse = playerPos - spawnPos;

		// �Q�̃x�N�g���̊O�ς����߂�
		float cross = Vector2::cross(enemyToMouse, Vector2::down);
		// �Q�̃x�N�g���̓��ς����߂�
		float dot = Vector2::dot(enemyToMouse, Vector2::down);

		// �t�^���W�F���g���g���Č��������p�x�����߂�
		float result = -MathHelper::atan(cross, dot);

		// �e�̏������x
		auto initVelocity = Vector2(MathHelper::sin(result), -MathHelper::cos(result)) * 512.0f;

		// �G�̒ʏ�e���o��
		VirusEnemyBullet::create(spawnPos, initVelocity);

		//�e���˂�SE
		getComponent<SePlayer>().lock()->playSe();

		// �e���˃^�C�}�[��������
		m_shotTimer = 0.0f;
	}
}

void VirusEnemyScript5::PowerupItem()
{
	auto PowerupItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// �ړ����x�{����
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 20.0f;

	//�p���[�A�b�v�A�C�e��
	CorePowerupItem::create(PowerupItemPos, inivelocity);
}

void VirusEnemyScript5::RecoveryItem()
{
	auto RecoveryItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// �ړ����x�{����
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 20.0f;

	RecoveryItem::create(RecoveryItemPos, inivelocity);
}

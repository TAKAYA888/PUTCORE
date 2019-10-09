#include "VirusEnemyScript3-1.h"

#include "../../Explosion/Explosion.h"
#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "../../Item/CorePowerupItem/CorePowerupItem.h"
#include "../../Player/PlayerScript.h"
#include "../../Item/RecoveryItem/RecoveryItem.h"

VirusEnemyScript3_1::VirusEnemyScript3_1()
{
	timer = 0;	

	add_core_bullet = 0;

	// �v���C���[�̈ʒu���擾
	playerPos = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();

	playerFrag = true;

	counter = 0;
}

//���t���[���Ă΂��
void VirusEnemyScript3_1::update()
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

		GameObjectManager::sendMessage(DIE_Enemy3_1);
		getGameObject().lock()->destroy();
	}
}

//�ՓˊJ�n�ŌĂ΂��
void VirusEnemyScript3_1::onCollisionEnter(GameObjectPtr other)
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
void VirusEnemyScript3_1::onCollisionStay(GameObjectPtr other)
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
void VirusEnemyScript3_1::onCollisionExit(GameObjectPtr other)
{
}

void VirusEnemyScript3_1::handleMessage(int  eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
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
void VirusEnemyScript3_1::move()
{
	if (timer < 2.3f)
	{
		// ���g�̉�]�p�x
		float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

		// �G�l�~�[�̈ʒu���擾
		auto enemyPos = getComponent<Transform2D>().lock()->getWorldPosition();

		if (playerFrag)
		{
			// �v���C���[�̈ʒu���擾
			playerPos = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();
		}

		// �u�v���C���[�v->�u�G�l�~�[�v�̃x�N�g�������߂�
		auto enemyToMouse = playerPos - enemyPos;

		// �Q�̃x�N�g���̊O�ς����߂�
		float cross = Vector2::cross(enemyToMouse, Vector2::down);
		// �Q�̃x�N�g���̓��ς����߂�
		float dot = Vector2::dot(enemyToMouse, Vector2::down);

		// �t�^���W�F���g���g���Č��������p�x�����߂�
		float result = -MathHelper::atan(cross, dot);

		Lasttimeresult = result;
	}
	// �ړ����x�{����
	auto velocity = Vector2(MathHelper::sin(Lasttimeresult), -MathHelper::cos(Lasttimeresult)) * 20.0f;

	// �������������ւƉ�]����
	getComponent<Transform2D>().lock()->setLocalRotationDeg(Lasttimeresult);

	// �ړ�����
	getComponent<InertialMovement2D>().lock()->addForce(velocity);
}

void VirusEnemyScript3_1::PowerupItem()
{
	auto PowerupItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// �ړ����x�{����
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 20.0f;

	//�p���[�A�b�v�A�C�e��
	CorePowerupItem::create(PowerupItemPos, inivelocity);
}

void VirusEnemyScript3_1::RecoveryItem()
{
	auto RecoveryItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// �ړ����x�{����
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 20.0f;

	RecoveryItem::create(RecoveryItemPos, inivelocity);
}

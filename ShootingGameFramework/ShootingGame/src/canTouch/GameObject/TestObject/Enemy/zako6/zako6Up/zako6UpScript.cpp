#include "zako6UpScript.h"
#include "../../../Explosion_Enemy/Explosion_Enemy.h"
#include "../../../Item/CorePowerupItem/CorePowerupItem.h"
#include "../../../Item/RecoveryItem/RecoveryItem.h"
#include "../../../Player/PlayerScript.h"

zako6UpScript::zako6UpScript()
{
	add_core_bullet = 0;

	counter = 0;

	playerFrag = true;
}

void zako6UpScript::update()
{
	auto player = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER);

	if (playerFrag)
	{
		add_core_bullet = player.lock()->getComponent<PlayerScript>().lock()->add_core_bullet;
	}

	move();

	Random::randomize();

	//�̗͂�0�ȉ��ɂȂ�����
	if (m_hp <= 0)
	{
		counter = Random::getRandI(1, 4);

		if (counter == 1) {

			counter = Random::getRandI(1, 10);

			if (counter <= 3)
			{
				// �p���[�A�b�v�A�C�e��
				PowerupItem();
			}
			else
			{
				// �񕜃A�C�e��
				RecoveryItem();
			}
		}

		GameObjectManager::sendMessage(DIE_Enemy6);
		getGameObject().lock()->destroy();
	}
}

void zako6UpScript::onCollisionEnter(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_PLAYER_BULLET�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER || other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER_BULLET)
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

		// �̗͂�-3����
		m_hp -= 3;
	}

	//�Փˑ���̃^�O���uGAME_OBJECT_TAG_CORE�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_CORE)
	{
		// �����𐶐�����
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// �̗͂�-10����
		m_hp -= 10;
	}
}

void zako6UpScript::onCollisionStay(GameObjectPtr other)
{
}

void zako6UpScript::onCollisionExit(GameObjectPtr other)
{
}

void zako6UpScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	//�����Q�[���v���C�I�u�W�F�N�g�����˂Ƃ���ꂽ��
	if (eventMessageType == DIE_GAMEPLAY_OBJECT || eventMessageType == DIE_BOSS3_DEAD)
	{
		//���̃R���|�[�l���g������
		getGameObject().lock()->destroy();
	}

	if (eventMessageType == DIE_PLAYER)
	{
		playerFrag = false;
	}
}

void zako6UpScript::onDestroy()
{
	
}

void zako6UpScript::move()
{
	// �ړ����x�{����
	auto velocity = Vector2(MathHelper::sin(180), MathHelper::cos(180)) * 20.0f;


	// �ړ�����
	getComponent<InertialMovement2D>().lock()->addForce(velocity);
}

void zako6UpScript::PowerupItem()
{
	auto PowerupItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// �ړ����x�{����
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 100.0f;

	//�p���[�A�b�v�A�C�e��
	CorePowerupItem::create(PowerupItemPos, inivelocity);
}

void zako6UpScript::RecoveryItem()
{
	auto RecoveryItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// �ړ����x�{����
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 100.0f;

	RecoveryItem::create(RecoveryItemPos, inivelocity);
}



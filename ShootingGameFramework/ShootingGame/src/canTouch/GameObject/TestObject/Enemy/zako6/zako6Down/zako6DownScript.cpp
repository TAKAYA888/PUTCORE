#include "zako6DownScript.h"
#include "../../../Explosion_Enemy/Explosion_Enemy.h"
#include "../../../Item/CorePowerupItem/CorePowerupItem.h"
#include "../../../Item/RecoveryItem/RecoveryItem.h"
#include "../../../Player/PlayerScript.h"

zako6DownScript::zako6DownScript()
{
	add_core_bullet = 0;

	counter = 0;

	playerFrag = true;
}

void zako6DownScript::update()
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

		GameObjectManager::sendMessage(DIE_Enemy6);
		getGameObject().lock()->destroy();
	}
}

void zako6DownScript::onCollisionEnter(GameObjectPtr other)
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

void zako6DownScript::onCollisionStay(GameObjectPtr other)
{
}

void zako6DownScript::onCollisionExit(GameObjectPtr other)
{
}

void zako6DownScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
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

void zako6DownScript::onDestroy()
{	
}

void zako6DownScript::move()
{
	// �ړ����x�{����
	auto velocity = Vector2(MathHelper::sin(0), MathHelper::cos(0)) * 20.0f;


	// �ړ�����
	getComponent<InertialMovement2D>().lock()->addForce(velocity);
}

void zako6DownScript::PowerupItem()
{
	auto PowerupItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// �ړ����x�{����
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 100.0f;

	//�p���[�A�b�v�A�C�e��
	CorePowerupItem::create(PowerupItemPos, inivelocity);
}

void zako6DownScript::RecoveryItem()
{
	auto RecoveryItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// �ړ����x�{����
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 100.0f;

	RecoveryItem::create(RecoveryItemPos, inivelocity);
}

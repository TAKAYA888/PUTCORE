#include "BossCoreScript.h"
#include "BossCoreDeadScript.h"
#include "../../../Explosion_Enemy/Explosion_Enemy.h"
#include "../../../EnemyBullet/EnemyNormalBullet/EnemyNormalBullet.h"
#include <string>
#include<iostream>

BossCore1Script::BossCore1Script()
{
	timer = 0;
	angle = 0;
	shotfrag = true;
}

void BossCore1Script::update()
{
	bool ActiveFrag = getComponent<BossCore1Script>().lock()->isActive();
	if (ActiveFrag)
	{
		getComponent<BossCoreDeadScript>().lock()->setActive(false);
	}

	if (m_hp < 0)
	{
		getComponent<BossCoreDeadScript>().lock()->setActive(true);
		getComponent<BossCore1Script>().lock()->setActive(false);
		m_hp = 15;
	}

	m_shotTimer -= TktkTime::deltaTime();
	if (m_shotTimer < -10.0f)
	{
		m_shotTimer = 0.0f;
	}
	timer += TktkTime::deltaTime();
	Vector2 nowPos = getComponent<Transform2D>().lock()->getLocalPosition();
	if (timer < 5.0f)
	{
		angle = timer * 10;
	}
	else if (timer < 15.0f)
	{
		angle -= TktkTime::deltaTime() * 10;
	}
	else if (timer < 16)
	{
		shotfrag = false;
	}
	else
	{
		angle = 0;
		timer = 0;
		shotfrag = true;
	}

	auto initVelocity1 = Vector2(MathHelper::sin(250.0f + angle), MathHelper::cos(250.0f + angle)) * 512.0f;
	auto initVelocity2 = Vector2(MathHelper::sin(280.0f + angle), MathHelper::cos(280.0f + angle)) * 512.0f;

	if (m_shotTimer < 0.0f && shotfrag)
	{
		EnemyNormalBullet::create(nowPos, initVelocity1);
		EnemyNormalBullet::create(nowPos, initVelocity2);
		m_shotTimer = 0.2f;
	}

}

void BossCore1Script::onCollisionEnter(GameObjectPtr other)
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
}

void BossCore1Script::onCollisionStay(GameObjectPtr other)
{
}

void BossCore1Script::onCollisionExit(GameObjectPtr other)
{
}

void BossCore1Script::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	//�����Q�[���v���C�I�u�W�F�N�g�����˂Ƃ���ꂽ��
	if (eventMessageType == DIE_BOSS2_DEAD)
	{
		//���̃R���|�[�l���g������
		getGameObject().lock()->destroy();
	}
}

void BossCore1Script::onDestroy()
{
}

void BossCore1Script::Shot()
{
}
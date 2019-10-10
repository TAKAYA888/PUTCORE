#include "BossCoreScript.h"
#include "BossCoreDeadScript.h"
#include "../../../Explosion_Enemy/Explosion_Enemy.h"
#include "../../../EnemyBullet/VirusEnemyBullet/VirusEnemyBullet.h"
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
	//���̃X�N���v�g��Active�t���O���󂯎��
	bool ActiveFrag = getComponent<BossCore1Script>().lock()->isActive();
	//����Active�t���O��true�Ȃ�
	if (ActiveFrag)
	{
		//���L�̃R���|�[�l���g��false�ɂ���
		getComponent<BossCoreDeadScript>().lock()->setActive(false);
	}

	//����Hp��0�ȉ��Ȃ�
	if (m_hp <= 0)
	{
		//���L�̃R���|�[�l���g��true�ɂ���
		getComponent<BossCoreDeadScript>().lock()->setActive(true);
		//���L�̃R���|�[�l���g��false�ɂ���
		getComponent<BossCore1Script>().lock()->setActive(false);
		//Hp��15�ɂ���
		m_hp = 15;
	}

	//�V���[�g�^�C�}�[���J�E���g�_�E������
	m_shotTimer -= TktkTime::deltaTime();
	//�V���[�g�^�C�}�[��-10�ȉ��ɂȂ�Ȃ��悤�ɂ���
	if (m_shotTimer < -10.0f)
	{
		m_shotTimer = 0.0f;
	}
	//�^�C�}�[���J�E���g�A�b�v����
	timer += TktkTime::deltaTime();
	//���݂̍��W���󂯎��
	Vector2 nowPos = getComponent<Transform2D>().lock()->getLocalPosition();
	//�^�C�}�[��5�b�ȏ�ɂȂ�����
	if (timer < 5.0f)
	{
		//�p�x��ς���
		angle += TktkTime::deltaTime() * 10;
	}
	else if (timer < 15.0f)
	{
		//�p�x��ς���
		angle -= TktkTime::deltaTime() * 10;
	}
	else if (timer < 20.5f)
	{
		//�V���b�g�t���O��false�ɂ���
		shotfrag = false;
	}
	else
	{
		angle = 0;
		timer = 0;
		shotfrag = true;
	}

	//���x�Ɗp�x��ݒ肷��
	auto initVelocity1 = Vector2(MathHelper::sin(250.0f + angle), MathHelper::cos(250.0f + angle)) * 512.0f;
	auto initVelocity2 = Vector2(MathHelper::sin(280.0f + angle), MathHelper::cos(280.0f + angle)) * 512.0f;

	//�e������
	if (m_shotTimer < 0.0f && shotfrag)
	{
		VirusEnemyBullet::create(nowPos, initVelocity1);
		VirusEnemyBullet::create(nowPos, initVelocity2);
		m_shotTimer = 0.5f;
		//�e���˂�SE
		getComponent<SePlayer>().lock()->playSe();
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
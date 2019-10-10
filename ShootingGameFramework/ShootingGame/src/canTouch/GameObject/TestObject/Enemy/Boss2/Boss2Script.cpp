#include "Boss2Script.h"
#include "BossCore1/BossCore1.h"
#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "BossCore2/BossCore2.h"
#include "../../EnemyBullet/VirusEnemyBullet/VirusEnemyBullet.h"
#include "../Boss/BossDead/BossDead.h"

Boss2Script::Boss2Script()
{
	timer = 0;
	//boss�R�A�P�̐���
	BossCore1::create(Vector2(1450, 400), 0);
	//boss�R�A�Q�̐���
	BossCore2::create(Vector2(1450, 700), 0);
}

void Boss2Script::update()
{
	//�^�C�}�[�̃J�E���g�A�b�v
	timer += TktkTime::deltaTime();
	//���݂̍��W���󂯎��
	Vector2 nowPos = getComponent<Transform2D>().lock()->getLocalPosition();
	//����15.5�b�ȏ�o�߂�����
	if (timer > 15.5f)
	{
		//5��e�𐶐�����
		for (float i = 0; i <= 60; i += 15)
		{
			//�����Ƒ��x�̐ݒ�
			auto initVelocity1 = Vector2(MathHelper::sin(240.0f + i), MathHelper::cos(240.0f + i)) * 512.0f;
			//�e�̐���
			VirusEnemyBullet::create(nowPos, initVelocity1);
			//�e���˂�SE
			getComponent<SePlayer>().lock()->playSe();
		}
		//�^�C�}�[�̃��Z�b�g
		timer = 0;
	}

	//����Hp��0�ȉ��ɂȂ�����
	if (m_hp <= 0)
	{
		BossDead::create(getComponent<Transform2D>().lock()->getWorldPosition());
		// �������E��
		getGameObject().lock()->destroy();
	}
}

void Boss2Script::onCollisionEnter(GameObjectPtr other)
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

void Boss2Script::onCollisionStay(GameObjectPtr other)
{
}

void Boss2Script::onCollisionExit(GameObjectPtr other)
{
}

void Boss2Script::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	//�����Q�[���v���C�I�u�W�F�N�g�����˂Ƃ���ꂽ��
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		//���̃R���|�[�l���g������
		getGameObject().lock()->destroy();
	}
}

void Boss2Script::onDestroy()
{
	//���񂾂Ƃ��ɂ��̃��b�Z�[�W���΂�
	GameObjectManager::sendMessage(DIE_BOSS2_DEAD);
}

void Boss2Script::Shot()
{
}


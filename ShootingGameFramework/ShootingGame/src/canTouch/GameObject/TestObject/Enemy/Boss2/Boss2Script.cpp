#include "Boss2Script.h"
#include "BossCore1/BossCore1.h"
#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "BossCore2/BossCore2.h"
#include "../../EnemyBullet/EnemyNormalBullet/EnemyNormalBullet.h"

Boss2Script::Boss2Script()
{
	timer = 0;
	BossCore1::create(Vector2(900, 200), 0);
	BossCore2::create(Vector2(900, 550), 0);
}

void Boss2Script::update()
{
	timer += TktkTime::deltaTime();
	Vector2 nowPos = getComponent<Transform2D>().lock()->getLocalPosition();
	if (timer > 15.5f)
	{
		for (float i = 0; i <= 60; i += 15)
		{
			auto initVelocity1 = Vector2(MathHelper::sin(240.0f + i), MathHelper::cos(240.0f + i)) * 512.0f;
			EnemyNormalBullet::create(nowPos, initVelocity1);
		}
		timer = 0;
	}

	if (m_hp < 0)
	{
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
	GameObjectManager::sendMessage(DIE_BOSS2_DEAD);
}

void Boss2Script::Shot()
{
}


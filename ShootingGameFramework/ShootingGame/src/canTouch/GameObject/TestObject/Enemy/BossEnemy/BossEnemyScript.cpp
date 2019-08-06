#include "BossEnemyScript.h"

#include "../../EnemyBullet/EnemyNormalBullet/EnemyNormalBullet.h"
#include "../../Explosion/Explosion.h"

BossEnemyScript::BossEnemyScript()
{
}

// ���t���[���Ă΂��
void BossEnemyScript::update()
{
	// �ړ�
	move();

	// �e�𔭎�
	shot();

	// �̗͂��O�ȉ��ɂȂ�����
	if (m_hp <= 0)
	{
		//�Q�[���N���A�V�[���Ɉڍs����
		SceneManager::changeScene(CLEAR_SCENE);
		// �������E��
		getGameObject().lock()->destroy();
	}
}

// �ՓˊJ�n�ŌĂ΂��
void BossEnemyScript::onCollisionEnter(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_PLAYER_BULLET�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER_BULLET)
	{
		// �����𐶐�����
		Explosion::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// �̗͂�-1����
		m_hp--;
	}
}

// �Փ˒��ŌĂ΂��
void BossEnemyScript::onCollisionStay(GameObjectPtr other)
{
}

// �ՓˏI���ŌĂ΂��
void BossEnemyScript::onCollisionExit(GameObjectPtr other)
{
}

// ���b�Z�[�W��M���ɌĂ΂��
void BossEnemyScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	// �󂯎�������b�Z�[�W���uENEMY_BOSS_DEAD�v��������
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

// �����钼�O�ɌĂ΂��
void BossEnemyScript::onDestroy()
{
	
	GameObjectManager::sendMessage(ENEMY_BOSS_DEAD);
}

// �ړ�
void BossEnemyScript::move()
{
	// ���g�̉�]�p�x
	float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

	// �ړ����x�{����
	auto velocity = Vector2(MathHelper::sin(rotationDeg), -MathHelper::cos(rotationDeg)) * 5.0f;

	// �ړ�����
	getComponent<InertialMovement2D>().lock()->addForce(velocity);
}

// �e�𔭎�
void BossEnemyScript::shot()
{
	// �e���˃^�C�}�[���X�V
	m_shotTimer += TktkTime::deltaTime();

	// �e���˃^�C�}�[�����ˎ��ԂɂȂ�����
	if (m_shotTimer > m_shotInterval)
	{
		// �e�̏o�����W
		auto spawnPos = getComponent<Transform2D>().lock()->getWorldPosition();

		// ���g�̉�]�p�x
		float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

		// �e�̏������x
		auto initVelocity = Vector2(MathHelper::sin(rotationDeg), -MathHelper::cos(rotationDeg)) * 512.0f;

		// �G�̒ʏ�e���o��
		EnemyNormalBullet::create(spawnPos, initVelocity);

		// �e���˃^�C�}�[��������
		m_shotTimer = 0.0f;
	}
}

#include "NormalEnemyScript.h"

#include "../../EnemyBullet/EnemyNormalBullet/EnemyNormalBullet.h"
#include "../../Explosion/Explosion.h"

NormalEnemyScript::NormalEnemyScript()
{
}

// ���t���[���Ă΂��
void NormalEnemyScript::update()
{
	// �ړ�
	move();
	
	// �e�𔭎�
	shot();

	// �̗͂��O�ȉ��ɂȂ�����
	if (m_hp <= 0)
	{
		getComponent<SePlayer>().lock()->playSe();
		// �������E��
		getGameObject().lock()->destroy();
	}
}

// �ՓˊJ�n�ŌĂ΂��
void NormalEnemyScript::onCollisionEnter(GameObjectPtr other)
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
void NormalEnemyScript::onCollisionStay(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_PLAYER�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER)
	{
		// �����𐶐�����
		Explosion::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// �̗͂�-1����
		m_hp--;
	}
}

// �ՓˏI���ŌĂ΂��
void NormalEnemyScript::onCollisionExit(GameObjectPtr other)
{
}

void NormalEnemyScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

// �ړ�
void NormalEnemyScript::move()
{
	// ���g�̉�]�p�x
	float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

	// �ړ����x�{����
	auto velocity = Vector2(MathHelper::sin(rotationDeg), -MathHelper::cos(rotationDeg)) * 20.0f;


	// �ړ�����
	getComponent<InertialMovement2D>().lock()->addForce(velocity);
}

// �e�𔭎�
void NormalEnemyScript::shot()
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

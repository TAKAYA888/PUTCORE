#include "VirusEnemyScript3-1.h"

#include "../../Explosion/Explosion.h"
#include "../../Explosion_Enemy/Explosion_Enemy.h"

VirusEnemyScript3_1::VirusEnemyScript3_1()
{
	timer = 0;
}

//���t���[���Ă΂��
void VirusEnemyScript3_1::update()
{
	timer += TktkTime::deltaTime();

	//�ړ�
	move();

	//�̗͂�0�ȉ��ɂȂ�����
	if (m_hp <= 0)
	{
		getGameObject().lock()->destroy();
	}
}

//�ՓˊJ�n�ŌĂ΂��
void VirusEnemyScript3_1::onCollisionEnter(GameObjectPtr other)
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
}

//�Փ˒��ŌĂ΂��
void VirusEnemyScript3_1::onCollisionStay(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_PLAYER�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER || other.lock()->getTag() == GAME_OBJECT_TAG_CORE_BULLET)
	{
		// �����𐶐�����
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// �̗͂�-1����
		m_hp--;
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

		// �v���C���[�̈ʒu���擾
		Vector2 playerPos = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();

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
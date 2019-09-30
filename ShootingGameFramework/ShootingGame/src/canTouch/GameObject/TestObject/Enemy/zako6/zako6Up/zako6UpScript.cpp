#include "zako6UpScript.h"
#include "../../../Explosion_Enemy/Explosion_Enemy.h"

zako6UpScript::zako6UpScript()
{

}

void zako6UpScript::update()
{
	move();

	//�̗͂�0�ȉ��ɂȂ�����
	if (m_hp <= 0)
	{
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


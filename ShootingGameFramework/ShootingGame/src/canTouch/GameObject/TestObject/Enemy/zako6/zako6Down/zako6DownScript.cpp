#include "zako6DownScript.h"
#include "../../../Explosion_Enemy/Explosion_Enemy.h"

zako6DownScript::zako6DownScript()
{

}

void zako6DownScript::update()
{
	move();

	//�̗͂�0�ȉ��ɂȂ�����
	if (m_hp <= 0)
	{
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
}

void zako6DownScript::onDestroy()
{
	//���񂾂Ƃ��ɂ��̃��b�Z�[�W���΂�
	GameObjectManager::sendMessage(DIE_Enemy6);
}

void zako6DownScript::move()
{
	// �ړ����x�{����
	auto velocity = Vector2(MathHelper::sin(0), MathHelper::cos(0)) * 20.0f;


	// �ړ�����
	getComponent<InertialMovement2D>().lock()->addForce(velocity);
}
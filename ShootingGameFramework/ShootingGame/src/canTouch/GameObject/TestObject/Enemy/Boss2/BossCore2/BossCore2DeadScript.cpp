#include "BossCore2DeadScript.h"
#include "BossCore2Script.h"
#include "../../../Explosion_Enemy/Explosion_Enemy.h"

BossCore2DeadScript::BossCore2DeadScript()
{
	timer = 0;
}

void BossCore2DeadScript::update()
{
	//�J�E���g�A�b�v
	timer += TktkTime::deltaTime();
	//bossCore�Q�̃X�N���v�g���I���ɂȂ��Ă��邩�󂯎��
	bool ActivFlag = getComponent<BossCore2Script>().lock()->isActive();
	//����bossCore�Q�̃X�N���v�g��false�Ȃ�
	if (ActivFlag == false)
	{
		//�����蔻��A�����蔻��̕`��A�摜�̕`��A�A�j���[�V�����̃R���|�[�l���g��false�ɂ���
		getComponent<RectCollider>().lock()->setActive(false);
		getComponent<RectColliderWireFrameDrawer>().lock()->setActive(false);
		getComponent<Sprite2dDrawer>().lock()->setActive(false);
		getComponent<AnimatedSprite2d>().lock()->setActive(false);
	}

	//�������̃X�N���v�g���N������15�b�ȏ�o�߂�����
	if (timer > 15)
	{
		//�����蔻��A�����蔻��̕`��A�摜�̕`��A�A�j���[�V�����̃R���|�[�l���g��true�ɂ���
		getComponent<BossCore2Script>().lock()->setActive(true);
		getComponent<RectCollider>().lock()->setActive(true);
		getComponent<RectColliderWireFrameDrawer>().lock()->setActive(true);
		getComponent<Sprite2dDrawer>().lock()->setActive(true);
		getComponent<AnimatedSprite2d>().lock()->setActive(true);
		//�^�C�}�[�̃��Z�b�g
		timer = 0;
	}
}

void BossCore2DeadScript::onCollisionEnter(GameObjectPtr other)
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

void BossCore2DeadScript::onCollisionStay(GameObjectPtr other)
{
}

void BossCore2DeadScript::onCollisionExit(GameObjectPtr other)
{
}

void BossCore2DeadScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	//�����Q�[���v���C�I�u�W�F�N�g�����˂Ƃ���ꂽ��
	if (eventMessageType == DIE_BOSS2_DEAD)
	{
		//���̃R���|�[�l���g������
		getGameObject().lock()->destroy();
	}
}

void BossCore2DeadScript::onDestroy()
{
}
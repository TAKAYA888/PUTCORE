#include "PlayerScript.h"

#include "../PlayerBullet/PlayerBullet.h"
#include "../Explosion/Explosion.h"

//#include <string>
//#include<iostream>

PlayerScript::PlayerScript(float moveSpeed)
	: m_moveSpeed(moveSpeed)
{
	invincibleTime = 0;
}

// ���t���[���Ă΂��
void PlayerScript::update()
{
	// �^�C�}�[�J�E���g�A�b�v
	invincibleTime--;
	if (invincibleTime < 0)
	{
		invincibleTime = 0;
	}

	if ((invincibleTime % 5) == 1)
	{
		if (getComponent<Sprite2dDrawer>().lock()->isActive())
		{
			getComponent<Sprite2dDrawer>().lock()->setActive(false);
		}
		else
		{
			getComponent<Sprite2dDrawer>().lock()->setActive(true);
		}
	}

	if (invincibleTime > 0)
	{
		getComponent<RectCollider>().lock()->setActive(false);
	}
	else if (invincibleTime <= 0)
	{
		getComponent<RectCollider>().lock()->setActive(true);
	}

	// ���͂ɂ��ړ�
	inputToMove();

	// ���͂ɂ���]
	inputToRotate();

	// ���͂ɂ�锭��
	inputToShot();


	// �̗͂��O�ȉ��ɂȂ�����
	if (m_curHp <= 0)
	{
		//�Q�[���I�[�o�[�Ɉڍs����
		SceneManager::changeScene(GAMEOVER_SCENE);
		// �������E��
		getGameObject().lock()->destroy();
	}
}

// �ՓˊJ�n�ŌĂ΂��
void PlayerScript::onCollisionEnter(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_ENEMY_BULLET�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY_BULLET)
	{
		// �����𐶐�����
		Explosion::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);
		//���G���Ԃ����Z����
		invincibleTime = 90;
		// �̗͂�-1����
		m_curHp--;
	}
}

// �Փ˒��ŌĂ΂��
void PlayerScript::onCollisionStay(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_ENEMY�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY)
	{
		// �����𐶐�����
		Explosion::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		//���G���Ԃ����Z����
		invincibleTime = 90;
		// �̗͂�-1����
		m_curHp--;
	}
}

// �ՓˏI���ŌĂ΂��
void PlayerScript::onCollisionExit(GameObjectPtr other)
{
}

void PlayerScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

// �ő�̗̑͂��擾
int PlayerScript::getMaxHp() const
{
	return m_maxHp;
}

// ���݂̗̑͂��擾
int PlayerScript::getCurHp() const
{
	return m_curHp;
}

// ���͂ɂ��ړ�
void PlayerScript::inputToMove()
{
	// �ړ�����
	Vector2 moveVelocity = Vector2::zero;

	// ���L�[�̓��͎�
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_UP))
	{
		moveVelocity.y = -1.0f;
	}

	// s�L�[�̓��͎�
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_DOWN))
	{
		moveVelocity.y = 1.0f;
	}

	// a�L�[�̓��͎�
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_LEFT))
	{
		moveVelocity.x = -1.0f;
	}

	// d�L�[�̓��͎�
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_RIGHT))
	{
		moveVelocity.x = 1.0f;
	}

	// �ړ������̃x�N�g���𐳋K������
	moveVelocity = Vector2::normalize(moveVelocity);

	// �ړ������Ƒ��x�̕������͂�^����
	getComponent<InertialMovement2D>().lock()->addForce(moveVelocity * m_moveSpeed);
}

// ���͂ɂ���]
void PlayerScript::inputToRotate()
{
	// �������������ւƉ�]����
	getComponent<Transform2D>().lock()->setLocalRotationDeg(0);
}

// ���͂ɂ�锭��
void PlayerScript::inputToShot()
{
	// ���N���b�N���͊J�n��
	if (Keyboard::getState(InputType::INPUT_BEGIN, KeyboardKeyType::KEYBOARD_Z))
	{
		//�v���C���[�̍��W�̎󂯎��
		auto playerPos = getComponent<Transform2D>().lock()->getWorldPosition();

		// �e�̏o�����W���W
		Vector2 bulletPos;
		bulletPos.x = playerPos.x + 35.0f;
		bulletPos.y = playerPos.y + 40.0f;

		// �e�̏������x
		auto initVelocity = Vector2(MathHelper::sin(90), -MathHelper::cos(90)) * 512.0f;

		// �v���C���[�̒e���o��
		PlayerBullet::create(bulletPos, initVelocity);
	}
}
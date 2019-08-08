#include "PlayerScript.h"

#include "../PlayerBullet/PlayerBullet.h"
#include "../Explosion/Explosion.h"

#include <string>
#include<iostream>

PlayerScript::PlayerScript(float moveSpeed)
	: m_moveSpeed(moveSpeed)
{
	invincibleTime = 0;
	flashTime = 0;
}

// ���t���[���Ă΂��
void PlayerScript::update()
{
	//�_�ŏ���
	if (flashTime <= 0.0f && invincibleTime>0)
	{
		if (getComponent<Sprite2dDrawer>().lock()->isActive())
		{
			getComponent<Sprite2dDrawer>().lock()->setActive(false);
		}
		else
		{
			getComponent<Sprite2dDrawer>().lock()->setActive(true);
		}
		flashTime = 0.12f;
	}
	else if(flashTime > 0.0f&& invincibleTime > 0)
	{
		// �^�C�}�[�J�E���g�_�E��
		flashTime -= TktkTime::deltaTime();
	}


	//std::cout << flashTime << std::endl;
	//// �^�C�}�[�J�E���g�_�E��
	invincibleTime-= TktkTime::deltaTime();
	//std::cout << invincibleTime << std::endl;
	//���G���Ԃ�0�ȉ��ɂ��Ȃ�
	if (invincibleTime < 0)
	{
		invincibleTime = 0;
	}
	//���G���Ԃ̏���
	if (invincibleTime > 0)
	{
		getComponent<RectCollider>().lock()->setActive(false);
	}
	else if (invincibleTime <= 0)
	{
		getComponent<RectCollider>().lock()->setActive(true);
		getComponent<Sprite2dDrawer>().lock()->setActive(true);
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
		invincibleTime = 1.5f;
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
		invincibleTime = 1.5f;
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
		moveVelocity.y = -3.0f;
	}

	// s�L�[�̓��͎�
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_DOWN))
	{
		moveVelocity.y = 3.0f;
	}

	// a�L�[�̓��͎�
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_LEFT))
	{
		moveVelocity.x = -3.0f;
	}

	// d�L�[�̓��͎�
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_RIGHT))
	{
		moveVelocity.x = 3.0f;
	}

	moveVelocity = Vector2::normalize(moveVelocity);

	//�v���C���[�̃|�W�V�������󂯂Ƃ�
	Vector2 a = getComponent<Transform2D>().lock()->getWorldPosition();

	//�v���C���[�̍��W�ɑ��x���{
	Vector2 movePostion = a + moveVelocity * 3;

	getComponent<Transform2D>().lock()->setLocalPosition(movePostion);

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
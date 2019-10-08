#include "PlayerScript.h"

#include "../PlayerBullet/PlayerBullet.h"
#include "../Explosion/Explosion.h"
#include "../Core/StayCore/Core.h"

#include <string>
#include<iostream>

PlayerScript::PlayerScript(float moveSpeed)
	: m_moveSpeed(moveSpeed)
{
	invincibleTime = 0;
	flashTime = 0;
	add_core_bullet = 3;
	PowerupCounter = 0;
}

// ���t���[���Ă΂��
void PlayerScript::update()
{
	//�_�ŏ���
	if (flashTime <= 0.0f && invincibleTime > 0)
	{
		//���݂��Ă��邩�����Ă��邩�B
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
	else if (flashTime > 0.0f&& invincibleTime > 0)
	{
		// �^�C�}�[�J�E���g�_�E��
		flashTime -= TktkTime::deltaTime();
	}


	//std::cout << flashTime << std::endl;
	//// �^�C�}�[�J�E���g�_�E��
	invincibleTime -= TktkTime::deltaTime();
	//std::cout << invincibleTime << std::endl;
	//���G���Ԃ�0�ȉ��ɂ��Ȃ�
	if (invincibleTime < 0.0f)
	{
		invincibleTime = 0.0f;
	}
	//���G���Ԃ̏���
	if (invincibleTime > 0.0f)
	{
		getComponent<RectCollider>().lock()->setActive(false);
		//getComponent<RectColliderWireFrameDrawer>().lock()->setActive(false);
	}
	else if (invincibleTime <= 0.0f)
	{
		getComponent<Sprite2dDrawer>().lock()->setActive(true);
		getComponent<RectCollider>().lock()->setActive(true);
		//getComponent<RectColliderWireFrameDrawer>().lock()->setActive(true);
	}


	// ���͂ɂ��ړ�
	inputToMove();

	// ���͂ɂ��ړ�
	BoxInputToMove();

	// ���͂ɂ���]
	inputToRotate();

	// ���͂ɂ�锭��
	inputToShot();


	// �̗͂��O�ȉ��ɂȂ�����
	if (m_curHp <= 0)
	{
		//���񂾂Ƃ��ɂ��̃��b�Z�[�W���΂�
		GameObjectManager::sendMessage(DIE_PLAYER);
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

	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_CORE_POWER_UP_ITEM�v��������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_CORE_POWER_UP_ITEM)
	{
		if (PowerupCounter < 3)
		{
			//�J�E���^�[��+1����
			PowerupCounter++;
		}
		else
		{
			add_core_bullet++;
		}
	}
}

// �Փ˒��ŌĂ΂��
void PlayerScript::onCollisionStay(GameObjectPtr other)
{
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

	if (eventMessageType == DIE_CORE)
	{
		//�R�A�𐶐�����
		Core::create(SCREEN_SIZE / 2);
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
	Vector2 playerPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// ���L�[�̓��͎�
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_UP)||GamePad::getState(GamePadNumber::GAME_PAD_NUMBER_1, InputType::INPUT_PUSHING,GamePadButtonType::GAME_PAD_LEFT_THUMB_BUTTON))
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
	//144Hz
	//Vector2 movePostion = a + moveVelocity * 9 * 60 / 144;
	//60Hz
	Vector2 movePostion = a + moveVelocity * 9;

	getComponent<Transform2D>().lock()->setLocalPosition(movePostion);
}

void PlayerScript::BoxInputToMove()
{
	//�ړ�����
	Vector2 moveVelocity = Vector2::zero;

	//���X�e�B�b�N�̌X�����擾
	moveVelocity = GamePad::getLeftStick(GamePadNumber::GAME_PAD_NUMBER_1);

	//�X�e�B�b�N�̕����ƍ��W����y���W���t�Ȃ̂Ŕ��]����
	moveVelocity.y *= -1.0f;

	//�X�e�B�b�N�̌X����0.01�ȉ��Ȃ�X����0�ɂ���
	if (moveVelocity.length() < 0.01f)
	{
		moveVelocity = Vector2::zero;
	}

	moveVelocity = Vector2::normalize(moveVelocity);

	Vector2 curPos = getComponent<Transform2D>().lock()->getLocalPosition();

	curPos += moveVelocity * 9 * (144 * TktkTime::deltaTime());

	getComponent<Transform2D>().lock()->setLocalPosition(curPos);
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
	if (Keyboard::getState(InputType::INPUT_BEGIN, KeyboardKeyType::KEYBOARD_Z) || GamePad::getState(GamePadNumber::GAME_PAD_NUMBER_1, InputType::INPUT_BEGIN, GamePadButtonType::GAME_PAD_B_BUTTON))
	{
		//�v���C���[�̍��W�̎󂯎��
		Vector2 playerPos = getComponent<Transform2D>().lock()->getWorldPosition();

		// �e�̏o�����W���W
		Vector2 bulletPos;
		bulletPos.x = playerPos.x + 35.0f;
		bulletPos.y = playerPos.y + 40.0f;

		// �e�̏������x
		auto initVelocity = Vector2(MathHelper::sin(90.0f), -MathHelper::cos(90.0f)) * 512.0f;

		// �v���C���[�̒e���o��
		PlayerBullet::create(bulletPos, initVelocity);
	}
}
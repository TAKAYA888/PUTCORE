#include "PlayerScript.h"

#include "../PlayerBullet/PlayerBullet.h"
#include "../Explosion/Explosion.h"

PlayerScript::PlayerScript(float moveSpeed)
	: m_moveSpeed(moveSpeed)
{
}

// ���t���[���Ă΂��
void PlayerScript::update()
{
	// ���͂ɂ��ړ�
	inputToMove();

	// ���͂ɂ���]
	inputToRotate();

	// ���͂ɂ�锭��
	inputToShot();

	// �̗͂��O�ȉ��ɂȂ�����
	if (m_curHp <= 0)
	{
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
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_W))
	{
		moveVelocity.y = -1.0f;
	}

	// s�L�[�̓��͎�
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_S))
	{
		moveVelocity.y = 1.0f;
	}

	// a�L�[�̓��͎�
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_A))
	{
		moveVelocity.x = -1.0f;
	}

	// d�L�[�̓��͎�
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_D))
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
	// �v���C���[�̈ʒu���擾
	auto playerPos = getComponent<Transform2D>().lock()->getWorldPosition();
	// �}�E�X�J�[�\���̈ʒu���擾
	auto mousePos = Mouse::getCursorPoint();

	// �u�v���C���[�v->�u�}�E�X�J�[�\���v�̃x�N�g�������߂�
	auto playerToMouse = mousePos - playerPos;

	// �Q�̃x�N�g���̊O�ς����߂�
	float cross = Vector2::cross(playerToMouse, Vector2::down);
	// �Q�̃x�N�g���̓��ς����߂�
	float dot = Vector2::dot(playerToMouse, Vector2::down);

	// �t�^���W�F���g���g���Č��������p�x�����߂�
	float result = -MathHelper::atan(cross, dot);

	// �������������ւƉ�]����
	getComponent<Transform2D>().lock()->setLocalRotationDeg(result);
}

// ���͂ɂ�锭��
void PlayerScript::inputToShot()
{
	// ���N���b�N���͊J�n��
	if (Mouse::getState(InputType::INPUT_BEGIN, MouseButtonType::MOUSE_LEFT_BUTTON))
	{
		// �e�̏o�����W
		auto spawnPos = getComponent<Transform2D>().lock()->getWorldPosition();

		// ���g�̉�]�p�x
		float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

		// �e�̏������x
		auto initVelocity = Vector2(MathHelper::sin(rotationDeg), -MathHelper::cos(rotationDeg)) * 512.0f;

		// �v���C���[�̒e���o��
		PlayerBullet::create(spawnPos, initVelocity);
	}
}
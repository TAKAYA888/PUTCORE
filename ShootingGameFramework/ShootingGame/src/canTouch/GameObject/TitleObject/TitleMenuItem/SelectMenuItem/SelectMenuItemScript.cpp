#include "SelectMenuItemScript.h"

//�ǉ��@float moveSpeed�@���@:m_moveSpeed(moveSpeed)
SelectMenuItemScript::SelectMenuItemScript(float moveSpeed)
	:m_moveSpeed(moveSpeed)
{
}

// ���t���[���Ă΂��
void SelectMenuItemScript::update()
{
	//�ǉ�
	Move();
	counter++;

	if (Stealth == 1)
	{
		m_curAlpha += m_increaseAlphaPerSec * TktkTime::deltaTime();

		if (m_curAlpha > 1.0f) m_curAlpha = 1.0f;

		getComponent<Sprite2dDrawer>().lock()->setBlendParam(m_curAlpha);
	}

	if (select == 1)
	{
		if (counter % 40 == 0)
		{
			getComponent<Sprite2dDrawer>().lock()->setActive(false);
		}
		else if (counter % 40 == 20)
		{
			getComponent<Sprite2dDrawer>().lock()->setActive(true);
		}
	}

	if (select == 3)
	{
		if (counter % 5 == 0)
		{
			getComponent<Sprite2dDrawer>().lock()->setActive(false);
		}
		else if (counter % 10 == 1)
		{
			getComponent<Sprite2dDrawer>().lock()->setActive(true);
		}
	}
}

// �ՓˊJ�n�ŌĂ΂��
void SelectMenuItemScript::onCollisionEnter(GameObjectPtr other)
{
}

// �Փ˒��ŌĂ΂��
void SelectMenuItemScript::onCollisionStay(GameObjectPtr other)
{
	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_CURSOR�v�ŃN���b�N�J�n����������
	//if (other.lock()->getTag() == GAME_OBJECT_TAG_CURSOR
	//	&& Mouse::getState(InputType::INPUT_BEGIN, MouseButtonType::MOUSE_LEFT_BUTTON))
	//{
		//getComponent<SePlayer>().lock()->playSe();
		// ���C���V�[���ɑJ�ڂ���
		//SceneManager::changeScene(MAIN_SCENE);

	//}
}

// �ՓˏI���ŌĂ΂��
void SelectMenuItemScript::onCollisionExit(GameObjectPtr other)
{
}

void SelectMenuItemScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

//�ǉ�
void SelectMenuItemScript::Move()
{
	if (select == 1 || select == 2 || select == 0)
	{
		if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_UP) )
		{
			select = 1;
		}
		else if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_DOWN) )
		{
			select = 2;
			getComponent<Sprite2dDrawer>().lock()->setActive(true);
		}
	}

	if (select == 1 && Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_SPACE))
	{
		getComponent<SePlayer>().lock()->playSe();
		counter = 0;
		select = 3;
	}

	else if (counter == 120 && select == 3)
	{
		// ���C���V�[���ɑJ�ڂ���
		SceneManager::changeScene(MAIN_SCENE);
	}

	if (counter >= 130)
	{
		Stealth = 1;

		Vector2 selfPos = getComponent<Transform2D>().lock()->getWorldPosition();

		Vector2 moveVelocity = Vector2::zero;

		moveVelocity.y = 1.0f;

		moveVelocity = Vector2::normalize(moveVelocity);

		getComponent<InertialMovement2D>().lock()->addForce(moveVelocity * m_moveSpeed);

		if (selfPos.y > SCREEN_SIZE.y - 250)
		{
			m_moveSpeed = 0;
		}
	}
}
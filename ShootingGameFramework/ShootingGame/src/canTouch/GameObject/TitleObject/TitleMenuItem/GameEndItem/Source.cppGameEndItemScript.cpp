#include "GameEndItemScript.h"

GameEndItemScript::GameEndItemScript(float moveSpeed)
	:m_moveSpeed(moveSpeed)
{
}

// ���t���[���Ă΂��
void GameEndItemScript::update()
{
	Move();
	counter++;

	if (select == 2)
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

	if (select == 4)
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
void GameEndItemScript::onCollisionEnter(GameObjectPtr other)
{
}

// �Փ˒��ŌĂ΂��
void GameEndItemScript::onCollisionStay(GameObjectPtr other)
{

	// �Փˑ���̃^�O���uGAME_OBJECT_TAG_CURSOR�v�ŃN���b�N�J�n����������
	if (other.lock()->getTag() == GAME_OBJECT_TAG_CURSOR
		&& Mouse::getState(InputType::INPUT_BEGIN, MouseButtonType::MOUSE_LEFT_BUTTON))
	{


		getComponent<SePlayer>().lock()->playSe();

		// ���C���V�[���ɑJ�ڂ���
		SceneManager::changeScene(MAIN_SCENE);
	}

}

// �ՓˏI���ŌĂ΂��
void GameEndItemScript::onCollisionExit(GameObjectPtr other)
{
}

void GameEndItemScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

//�ǉ�
void GameEndItemScript::Move()
{
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_UP))
	{
		select = 1;
		getComponent<Sprite2dDrawer>().lock()->setActive(true);
	}
	else if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_DOWN))
	{
		select = 2;
	}

	if (select == 2 && Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_SPACE))
	{
		getComponent<SePlayer>().lock()->playSe();
		counter = 0;
		select = 4;


	}

	else if (counter == 120 && select == 4)
	{
		// ���C���V�[���ɑJ�ڂ���
		SceneManager::changeScene(MAIN_SCENE);
	}

	if (counter >= 90)
	{

		Vector2 selfPos = getComponent<Transform2D>().lock()->getWorldPosition();

		Vector2 moveVelocity = Vector2::zero;

		moveVelocity.y = 1.0f;

		moveVelocity = Vector2::normalize(moveVelocity);

		getComponent<InertialMovement2D>().lock()->addForce(moveVelocity * m_moveSpeed);

		if (selfPos.y > SCREEN_SIZE.y - 300)
		{
			m_moveSpeed = 0;
		}
	}
}
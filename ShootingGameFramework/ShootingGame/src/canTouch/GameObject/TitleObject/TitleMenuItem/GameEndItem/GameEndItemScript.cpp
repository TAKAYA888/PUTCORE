#include "GameEndItemScript.h"

GameEndItemScript::GameEndItemScript(float moveSpeed)
	:m_moveSpeed(moveSpeed)
{
}

// 毎フレーム呼ばれる
void GameEndItemScript::update()
{
	Move();
	counter++;

	if (Stealth == 1)
	{
		m_curAlpha += m_increaseAlphaPerSec * TktkTime::deltaTime();

		if (m_curAlpha > 1.0f) m_curAlpha = 1.0f;

		getComponent<Sprite2dDrawer>().lock()->setBlendParam(m_curAlpha);
	}

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

// 衝突開始で呼ばれる
void GameEndItemScript::onCollisionEnter(GameObjectPtr other)
{
}

// 衝突中で呼ばれる
void GameEndItemScript::onCollisionStay(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_CURSOR」でクリック開始時だったら
//	if (other.lock()->getTag() == GAME_OBJECT_TAG_CURSOR
	//	&& Mouse::getState(InputType::INPUT_BEGIN, MouseButtonType::MOUSE_LEFT_BUTTON))
	//{
		//getComponent<SePlayer>().lock()->playSe();

		// メインシーンに遷移する
		//SceneManager::changeScene(MAIN_SCENE);
	//}
}

// 衝突終了で呼ばれる
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

//追加
void GameEndItemScript::Move()
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
		}
	}
	if (select == 2 && Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_SPACE))
	{
		getComponent<SePlayer>().lock()->playSe();
		counter = 0;
		select = 4;
	}

	if (counter == 120 && select == 4)
	{
		GameLoop::exitGame();
	}

	if (counter >= 150)
	{
		Stealth = 1;
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
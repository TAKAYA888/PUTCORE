#include "GameStartItemScript.h"

//追加　float moveSpeed　＆　:m_moveSpeed(moveSpeed)
GameStartItemScript::GameStartItemScript(float moveSpeed)
	:m_moveSpeed(moveSpeed)
{
}

// 毎フレーム呼ばれる
void GameStartItemScript::update()
{
	//追加
	Move();
	//左スティックの傾きを取得
	moveVelocity = GamePad::getLeftStick(GamePadNumber::GAME_PAD_NUMBER_1);

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

// 衝突開始で呼ばれる
void GameStartItemScript::onCollisionEnter(GameObjectPtr other)
{
}

// 衝突中で呼ばれる
void GameStartItemScript::onCollisionStay(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_CURSOR」でクリック開始時だったら
	//if (other.lock()->getTag() == GAME_OBJECT_TAG_CURSOR
	//	&& Mouse::getState(InputType::INPUT_BEGIN, MouseButtonType::MOUSE_LEFT_BUTTON))
	//{
		//getComponent<SePlayer>().lock()->playSe();
		// メインシーンに遷移する
		//SceneManager::changeScene(MAIN_SCENE);

	//}
}

// 衝突終了で呼ばれる
void GameStartItemScript::onCollisionExit(GameObjectPtr other)
{
}

void GameStartItemScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

//追加
void GameStartItemScript::Move()
{
	if (counter >= 200 && select != 3)
	{
		if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_UP) || (moveVelocity.y > 0.1 && moveVelocity.y < 1.0f))
		{
			select = 1;
		}
		else if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_DOWN) || (moveVelocity.y < -0.1 && moveVelocity.y > -1.0f))
		{
			select = 2;
			getComponent<Sprite2dDrawer>().lock()->setActive(true);
		}
	}

	if (counter >= 200 && select == 1 && (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_SPACE) || GamePad::getState(GamePadNumber::GAME_PAD_NUMBER_1, InputType::INPUT_BEGIN, GamePadButtonType::GAME_PAD_B_BUTTON)))
	{
		getComponent<SePlayer>().lock()->playSe();
		counter = 0;
		select = 3;
	}

	else if (counter == 120 && select == 3)
	{
		select = 0;
		counter = 0;
		// メインシーンに遷移する
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

		if (selfPos.y > SCREEN_SIZE.y - 350)
		{
			getComponent<InertialMovement2D>().lock()->setVelocity(Vector2(0, 0));
		}

	}
}
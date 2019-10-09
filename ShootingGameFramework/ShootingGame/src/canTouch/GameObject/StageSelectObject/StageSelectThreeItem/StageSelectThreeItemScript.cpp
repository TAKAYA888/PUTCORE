#include "StageSelectThreeItemScript.h"

//追加　float moveSpeed　＆　:m_moveSpeed(moveSpeed)
StageSelectThreeItemScript::StageSelectThreeItemScript(float moveSpeed)
	:m_moveSpeed(moveSpeed)
{
}

// 毎フレーム呼ばれる
void StageSelectThreeItemScript::update()
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
void StageSelectThreeItemScript::onCollisionEnter(GameObjectPtr other)
{
}

// 衝突中で呼ばれる
void StageSelectThreeItemScript::onCollisionStay(GameObjectPtr other)
{

}

// 衝突終了で呼ばれる
void StageSelectThreeItemScript::onCollisionExit(GameObjectPtr other)
{
}

void StageSelectThreeItemScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

//追加
void StageSelectThreeItemScript::Move()
{
	if (select == 0)
	{
		if (Keyboard::getState(InputType::INPUT_BEGIN, KeyboardKeyType::KEYBOARD_RIGHT) || (moveVelocity.x > 0.1f && moveVelocity.x < 1.0f))
		{
			select = 1;

		}

		getComponent<Sprite2dDrawer>().lock()->setActive(true);
	}
	else if (select == 1)
	{
		if (Keyboard::getState(InputType::INPUT_BEGIN, KeyboardKeyType::KEYBOARD_RIGHT) || (moveVelocity.x > 0.1f && moveVelocity.x < 1.0f))
		{
			select = 2;

		}
		else if (Keyboard::getState(InputType::INPUT_BEGIN, KeyboardKeyType::KEYBOARD_LEFT) || (moveVelocity.x < -0.1f&& moveVelocity.x > -1.0f))
		{
			select = 0;
		}

		getComponent<Sprite2dDrawer>().lock()->setActive(true);

	}
	else if (select >= 2)
	{

		if (Keyboard::getState(InputType::INPUT_BEGIN, KeyboardKeyType::KEYBOARD_LEFT) || ( moveVelocity.x < -0.1f && moveVelocity.x > -1.0f))
		{
			select = 1;
		}

		
	}


	if (select == 2 && (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_SPACE) || GamePad::getState(GamePadNumber::GAME_PAD_NUMBER_1, InputType::INPUT_BEGIN, GamePadButtonType::GAME_PAD_B_BUTTON)))
	{
		getComponent<SePlayer>().lock()->playSe();
		counter = 0;
		select = 3;
	}

	else if (counter == 120 && select == 3)
	{
		// メインシーンに遷移する
		SceneManager::changeScene(STAGE_THREE_SCENE);
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
			getComponent<InertialMovement2D>().lock()->setVelocity(Vector2(0, 0));
		}
	}
}
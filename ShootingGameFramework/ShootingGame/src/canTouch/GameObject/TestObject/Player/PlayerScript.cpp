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

// 毎フレーム呼ばれる
void PlayerScript::update()
{
	//点滅処理
	if (flashTime <= 0.0f && invincibleTime > 0)
	{
		//現在ついているか消えているか。
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
		// タイマーカウントダウン
		flashTime -= TktkTime::deltaTime();
	}


	//std::cout << flashTime << std::endl;
	//// タイマーカウントダウン
	invincibleTime -= TktkTime::deltaTime();
	//std::cout << invincibleTime << std::endl;
	//無敵時間を0以下にしない
	if (invincibleTime < 0.0f)
	{
		invincibleTime = 0.0f;
	}
	//無敵時間の処理
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


	// 入力による移動
	inputToMove();

	// 入力による移動
	BoxInputToMove();

	// 入力による回転
	inputToRotate();

	// 入力による発射
	inputToShot();


	// 体力が０以下になったら
	if (m_curHp <= 0)
	{
		//死んだときにこのメッセージを飛ばす
		GameObjectManager::sendMessage(DIE_PLAYER);
		//ゲームオーバーに移行する
		SceneManager::changeScene(GAMEOVER_SCENE);
		// 自分を殺す
		getGameObject().lock()->destroy();

	}
}

// 衝突開始で呼ばれる
void PlayerScript::onCollisionEnter(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_ENEMY_BULLET」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY_BULLET)
	{
		// 爆発を生成する
		Explosion::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);
		//無敵時間を加算する
		invincibleTime = 1.5f;
		// 体力を-1する
		m_curHp--;
	}

	// 衝突相手のタグが「GAME_OBJECT_TAG_ENEMY」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY)
	{
		// 爆発を生成する
		Explosion::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		//無敵時間を加算する
		invincibleTime = 1.5f;
		// 体力を-1する
		m_curHp--;
	}

	// 衝突相手のタグが「GAME_OBJECT_TAG_CORE_POWER_UP_ITEM」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_CORE_POWER_UP_ITEM)
	{
		if (PowerupCounter < 3)
		{
			//カウンターを+1する
			PowerupCounter++;
		}
		else
		{
			add_core_bullet++;
		}
	}
}

// 衝突中で呼ばれる
void PlayerScript::onCollisionStay(GameObjectPtr other)
{
}

// 衝突終了で呼ばれる
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
		//コアを生成する
		Core::create(SCREEN_SIZE / 2);
	}
}

// 最大の体力を取得
int PlayerScript::getMaxHp() const
{
	return m_maxHp;
}

// 現在の体力を取得
int PlayerScript::getCurHp() const
{
	return m_curHp;
}

// 入力による移動
void PlayerScript::inputToMove()
{
	// 移動方向
	Vector2 moveVelocity = Vector2::zero;
	Vector2 playerPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// ｗキーの入力時
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_UP)||GamePad::getState(GamePadNumber::GAME_PAD_NUMBER_1, InputType::INPUT_PUSHING,GamePadButtonType::GAME_PAD_LEFT_THUMB_BUTTON))
	{
		moveVelocity.y = -3.0f;
	}

	// sキーの入力時
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_DOWN))
	{
		moveVelocity.y = 3.0f;
	}

	// aキーの入力時
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_LEFT))
	{
		moveVelocity.x = -3.0f;
	}

	// dキーの入力時
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_RIGHT))
	{
		moveVelocity.x = 3.0f;
	}

	moveVelocity = Vector2::normalize(moveVelocity);

	//プレイヤーのポジションを受けとる
	Vector2 a = getComponent<Transform2D>().lock()->getWorldPosition();

	//プレイヤーの座標に速度を＋
	//144Hz
	//Vector2 movePostion = a + moveVelocity * 9 * 60 / 144;
	//60Hz
	Vector2 movePostion = a + moveVelocity * 9;

	getComponent<Transform2D>().lock()->setLocalPosition(movePostion);
}

void PlayerScript::BoxInputToMove()
{
	//移動方向
	Vector2 moveVelocity = Vector2::zero;

	//左スティックの傾きを取得
	moveVelocity = GamePad::getLeftStick(GamePadNumber::GAME_PAD_NUMBER_1);

	//スティックの方向と座標軸のy座標が逆なので反転する
	moveVelocity.y *= -1.0f;

	//スティックの傾きが0.01以下なら傾きを0にする
	if (moveVelocity.length() < 0.01f)
	{
		moveVelocity = Vector2::zero;
	}

	moveVelocity = Vector2::normalize(moveVelocity);

	Vector2 curPos = getComponent<Transform2D>().lock()->getLocalPosition();

	curPos += moveVelocity * 9 * (144 * TktkTime::deltaTime());

	getComponent<Transform2D>().lock()->setLocalPosition(curPos);
}

// 入力による回転
void PlayerScript::inputToRotate()
{
	// 向きたい方向へと回転する
	getComponent<Transform2D>().lock()->setLocalRotationDeg(0);
}

// 入力による発射
void PlayerScript::inputToShot()
{
	// 左クリック入力開始時
	if (Keyboard::getState(InputType::INPUT_BEGIN, KeyboardKeyType::KEYBOARD_Z) || GamePad::getState(GamePadNumber::GAME_PAD_NUMBER_1, InputType::INPUT_BEGIN, GamePadButtonType::GAME_PAD_B_BUTTON))
	{
		//プレイヤーの座標の受け取り
		Vector2 playerPos = getComponent<Transform2D>().lock()->getWorldPosition();

		// 弾の出現座標座標
		Vector2 bulletPos;
		bulletPos.x = playerPos.x + 35.0f;
		bulletPos.y = playerPos.y + 40.0f;

		// 弾の初期速度
		auto initVelocity = Vector2(MathHelper::sin(90.0f), -MathHelper::cos(90.0f)) * 512.0f;

		// プレイヤーの弾を出現
		PlayerBullet::create(bulletPos, initVelocity);
	}
}
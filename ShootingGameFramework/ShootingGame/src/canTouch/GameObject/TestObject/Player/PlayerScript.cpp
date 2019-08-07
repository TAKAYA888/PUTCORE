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

// 毎フレーム呼ばれる
void PlayerScript::update()
{
	// タイマーカウントアップ
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

	// 入力による移動
	inputToMove();

	// 入力による回転
	inputToRotate();

	// 入力による発射
	inputToShot();


	// 体力が０以下になったら
	if (m_curHp <= 0)
	{
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
		invincibleTime = 90;
		// 体力を-1する
		m_curHp--;
	}
}

// 衝突中で呼ばれる
void PlayerScript::onCollisionStay(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_ENEMY」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY)
	{
		// 爆発を生成する
		Explosion::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		//無敵時間を加算する
		invincibleTime = 90;
		// 体力を-1する
		m_curHp--;
	}
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

	// ｗキーの入力時
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_UP))
	{
		moveVelocity.y = -1.0f;
	}

	// sキーの入力時
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_DOWN))
	{
		moveVelocity.y = 1.0f;
	}

	// aキーの入力時
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_LEFT))
	{
		moveVelocity.x = -1.0f;
	}

	// dキーの入力時
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_RIGHT))
	{
		moveVelocity.x = 1.0f;
	}

	// 移動方向のベクトルを正規化する
	moveVelocity = Vector2::normalize(moveVelocity);

	// 移動方向と速度の分だけ力を与える
	getComponent<InertialMovement2D>().lock()->addForce(moveVelocity * m_moveSpeed);
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
	if (Keyboard::getState(InputType::INPUT_BEGIN, KeyboardKeyType::KEYBOARD_Z))
	{
		//プレイヤーの座標の受け取り
		auto playerPos = getComponent<Transform2D>().lock()->getWorldPosition();

		// 弾の出現座標座標
		Vector2 bulletPos;
		bulletPos.x = playerPos.x + 35.0f;
		bulletPos.y = playerPos.y + 40.0f;

		// 弾の初期速度
		auto initVelocity = Vector2(MathHelper::sin(90), -MathHelper::cos(90)) * 512.0f;

		// プレイヤーの弾を出現
		PlayerBullet::create(bulletPos, initVelocity);
	}
}
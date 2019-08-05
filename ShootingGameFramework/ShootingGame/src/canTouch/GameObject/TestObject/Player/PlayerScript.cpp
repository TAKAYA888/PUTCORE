#include "PlayerScript.h"

#include "../PlayerBullet/PlayerBullet.h"
#include "../Explosion/Explosion.h"

PlayerScript::PlayerScript(float moveSpeed)
	: m_moveSpeed(moveSpeed)
{
}

// 毎フレーム呼ばれる
void PlayerScript::update()
{
	// 入力による移動
	inputToMove();

	// 入力による回転
	inputToRotate();

	// 入力による発射
	inputToShot();

	// 体力が０以下になったら
	if (m_curHp <= 0)
	{
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
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_W))
	{
		moveVelocity.y = -1.0f;
	}

	// sキーの入力時
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_S))
	{
		moveVelocity.y = 1.0f;
	}

	// aキーの入力時
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_A))
	{
		moveVelocity.x = -1.0f;
	}

	// dキーの入力時
	if (Keyboard::getState(InputType::INPUT_PUSHING, KeyboardKeyType::KEYBOARD_D))
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
	// プレイヤーの位置を取得
	auto playerPos = getComponent<Transform2D>().lock()->getWorldPosition();
	// マウスカーソルの位置を取得
	auto mousePos = Mouse::getCursorPoint();

	// 「プレイヤー」->「マウスカーソル」のベクトルを求める
	auto playerToMouse = mousePos - playerPos;

	// ２つのベクトルの外積を求める
	float cross = Vector2::cross(playerToMouse, Vector2::down);
	// ２つのベクトルの内積を求める
	float dot = Vector2::dot(playerToMouse, Vector2::down);

	// 逆タンジェントを使って向きたい角度を求める
	float result = -MathHelper::atan(cross, dot);

	// 向きたい方向へと回転する
	getComponent<Transform2D>().lock()->setLocalRotationDeg(result);
}

// 入力による発射
void PlayerScript::inputToShot()
{
	// 左クリック入力開始時
	if (Mouse::getState(InputType::INPUT_BEGIN, MouseButtonType::MOUSE_LEFT_BUTTON))
	{
		// 弾の出現座標
		auto spawnPos = getComponent<Transform2D>().lock()->getWorldPosition();

		// 自身の回転角度
		float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

		// 弾の初期速度
		auto initVelocity = Vector2(MathHelper::sin(rotationDeg), -MathHelper::cos(rotationDeg)) * 512.0f;

		// プレイヤーの弾を出現
		PlayerBullet::create(spawnPos, initVelocity);
	}
}
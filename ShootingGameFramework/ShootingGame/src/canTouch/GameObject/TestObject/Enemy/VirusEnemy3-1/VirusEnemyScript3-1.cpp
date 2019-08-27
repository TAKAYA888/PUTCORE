#include "VirusEnemyScript3-1.h"

#include "../../Explosion/Explosion.h"
#include "../../Explosion_Enemy/Explosion_Enemy.h"

VirusEnemyScript3_1::VirusEnemyScript3_1()
{
	timer = 0;
}

//毎フレーム呼ばれる
void VirusEnemyScript3_1::update()
{
	timer += TktkTime::deltaTime();

	//移動
	move();

	//体力が0以下になったら
	if (m_hp <= 0)
	{
		getGameObject().lock()->destroy();
	}
}

//衝突開始で呼ばれる
void VirusEnemyScript3_1::onCollisionEnter(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_PLAYER_BULLET」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER_BULLET || other.lock()->getTag() == GAME_OBJECT_TAG_CORE_BULLET)
	{
		// 爆発を生成する
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// 体力を-1する
		m_hp--;
	}
}

//衝突中で呼ばれる
void VirusEnemyScript3_1::onCollisionStay(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_PLAYER」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER || other.lock()->getTag() == GAME_OBJECT_TAG_CORE_BULLET)
	{
		// 爆発を生成する
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// 体力を-1する
		m_hp--;
	}
}

//衝突終了で呼ばれる
void VirusEnemyScript3_1::onCollisionExit(GameObjectPtr other)
{
}

void VirusEnemyScript3_1::handleMessage(int  eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

//移動
void VirusEnemyScript3_1::move()
{
	if (timer < 2.3f)
	{
		// 自身の回転角度
		float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

		// エネミーの位置を取得
		auto enemyPos = getComponent<Transform2D>().lock()->getWorldPosition();

		// プレイヤーの位置を取得
		Vector2 playerPos = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();

		// 「プレイヤー」->「エネミー」のベクトルを求める
		auto enemyToMouse = playerPos - enemyPos;

		// ２つのベクトルの外積を求める
		float cross = Vector2::cross(enemyToMouse, Vector2::down);
		// ２つのベクトルの内積を求める
		float dot = Vector2::dot(enemyToMouse, Vector2::down);

		// 逆タンジェントを使って向きたい角度を求める
		float result = -MathHelper::atan(cross, dot);

		Lasttimeresult = result;
	}
	// 移動速度＋方向
	auto velocity = Vector2(MathHelper::sin(Lasttimeresult), -MathHelper::cos(Lasttimeresult)) * 20.0f;

	// 向きたい方向へと回転する
	getComponent<Transform2D>().lock()->setLocalRotationDeg(Lasttimeresult);

	// 移動する
	getComponent<InertialMovement2D>().lock()->addForce(velocity);
}
#include "NormalEnemyScript.h"

#include "../../EnemyBullet/EnemyNormalBullet/EnemyNormalBullet.h"
#include "../../Explosion/Explosion.h"

NormalEnemyScript::NormalEnemyScript()
{
}

// 毎フレーム呼ばれる
void NormalEnemyScript::update()
{
	// 移動
	move();
	
	// 弾を発射
	shot();

	// 体力が０以下になったら
	if (m_hp <= 0)
	{
		getComponent<SePlayer>().lock()->playSe();
		// 自分を殺す
		getGameObject().lock()->destroy();
	}
}

// 衝突開始で呼ばれる
void NormalEnemyScript::onCollisionEnter(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_PLAYER_BULLET」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER_BULLET)
	{
		// 爆発を生成する
		Explosion::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// 体力を-1する
		m_hp--;
	}
}

// 衝突中で呼ばれる
void NormalEnemyScript::onCollisionStay(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_PLAYER」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER)
	{
		// 爆発を生成する
		Explosion::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// 体力を-1する
		m_hp--;
	}
}

// 衝突終了で呼ばれる
void NormalEnemyScript::onCollisionExit(GameObjectPtr other)
{
}

void NormalEnemyScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

// 移動
void NormalEnemyScript::move()
{
	// 自身の回転角度
	float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

	// 移動速度＋方向
	auto velocity = Vector2(MathHelper::sin(rotationDeg), -MathHelper::cos(rotationDeg)) * 20.0f;


	// 移動する
	getComponent<InertialMovement2D>().lock()->addForce(velocity);
}

// 弾を発射
void NormalEnemyScript::shot()
{
	// 弾発射タイマーを更新
	m_shotTimer += TktkTime::deltaTime();

	// 弾発射タイマーが発射時間になったら
	if (m_shotTimer > m_shotInterval)
	{
		// 弾の出現座標
		auto spawnPos = getComponent<Transform2D>().lock()->getWorldPosition();

		// 自身の回転角度
		float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

		// 弾の初期速度
		auto initVelocity = Vector2(MathHelper::sin(rotationDeg), -MathHelper::cos(rotationDeg)) * 512.0f;

		// 敵の通常弾を出現
		EnemyNormalBullet::create(spawnPos, initVelocity);

		// 弾発射タイマーを初期化
		m_shotTimer = 0.0f;
	}
}

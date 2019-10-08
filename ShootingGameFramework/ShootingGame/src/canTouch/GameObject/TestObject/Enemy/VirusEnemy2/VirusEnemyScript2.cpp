#include "VirusEnemyScript2.h"

#include "../../EnemyBullet/VirusEnemyBullet/VirusEnemyBullet.h"
#include "../../Explosion/Explosion.h"
#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "../../Item/CorePowerupItem/CorePowerupItem.h"
#include "../../Player/PlayerScript.h"
#include "../../Item/RecoveryItem/RecoveryItem.h"

VirusEnemyScript2::VirusEnemyScript2()
{
	add_core_bullet = 0;

	// プレイヤーの位置を取得
	playerPos = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();

	playerFrag = true;

	counter = 0;
}

//毎フレーム呼ばれる
void VirusEnemyScript2::update()
{
	auto player = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER);

	add_core_bullet = player.lock()->getComponent<PlayerScript>().lock()->add_core_bullet;

	Random::randomize();

	//移動
	move();

	// 弾を発射
	shot();

	//体力が0以下になったら
	if (m_hp <= 0)
	{
		counter = Random::getRandI(0, 10);

		if (0 <= counter && counter < 2)
		{
			//`パワーアップアイテム
			PowerupItem();
		}
		else
		{
			//回復アイテム
			RecoveryItem();
		}

		GameObjectManager::sendMessage(DIE_Enemy2);
		getGameObject().lock()->destroy();
	}
}

//衝突開始で呼ばれる
void VirusEnemyScript2::onCollisionEnter(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_PLAYER_BULLET」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER_BULLET)
	{
		// 爆発を生成する
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// 体力を-1する
		m_hp--;
	}

	if (other.lock()->getTag() == GAME_OBJECT_TAG_CORE_BULLET)
	{
		// 爆発を生成する
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		//体力を-3する
		m_hp = m_hp - add_core_bullet;
	}
}

//衝突中で呼ばれる
void VirusEnemyScript2::onCollisionStay(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_PLAYER」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER)
	{
		// 爆発を生成する
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// 体力を-1する
		m_hp--;
	}

	if (other.lock()->getTag() == GAME_OBJECT_TAG_CORE_BULLET)
	{
		// 爆発を生成する
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		//体力を-3する
		m_hp = m_hp - add_core_bullet;
	}
}

//衝突終了で呼ばれる
void VirusEnemyScript2::onCollisionExit(GameObjectPtr other)
{
}

void VirusEnemyScript2::handleMessage(int  eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}

	if (eventMessageType == DIE_PLAYER)
	{
		playerFrag = false;
	}
}

//移動
void VirusEnemyScript2::move()
{
	// 自身の回転角度
	float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

	// 移動速度＋方向
	auto velocity = Vector2(MathHelper::sin(rotationDeg), -MathHelper::cos(rotationDeg)) * 15.0f;

	// 移動する
	getComponent<InertialMovement2D>().lock()->addForce(velocity);
}

//弾を発射
void VirusEnemyScript2::shot()
{
	// 弾発射タイマーを更新
	m_shotTimer += TktkTime::deltaTime();

	// 弾発射タイマーが発射時間になったら
	if (m_shotTimer > m_shotInterval)
	{
		// 弾の出現座標
		auto spawnPos = getComponent<Transform2D>().lock()->getWorldPosition();

		if (playerFrag)
		{
			// プレイヤーの位置を取得
		    playerPos = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();
		}

		// 自身の回転角度
		float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

		// 「プレイヤー」->「エネミー」のベクトルを求める
		auto enemyToMouse = playerPos - spawnPos;

		// ２つのベクトルの外積を求める
		float cross = Vector2::cross(enemyToMouse, Vector2::down);
		// ２つのベクトルの内積を求める
		float dot = Vector2::dot(enemyToMouse, Vector2::down);

		// 逆タンジェントを使って向きたい角度を求める
		float result = -MathHelper::atan(cross, dot);

		// 弾の初期速度
		auto initVelocity = Vector2(MathHelper::sin(result), -MathHelper::cos(result)) * 512.0f;

		// 敵の通常弾を出現
		VirusEnemyBullet::create(spawnPos, initVelocity);

		//弾発射のSE
		getComponent<SePlayer>().lock()->playSe();

		// 弾発射タイマーを初期化
		m_shotTimer = 0.0f;
	}
}

void VirusEnemyScript2::PowerupItem()
{
	auto PowerupItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// 移動速度＋方向
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 20.0f;

	//パワーアップアイテム
	CorePowerupItem::create(PowerupItemPos, inivelocity);
}

void VirusEnemyScript2::RecoveryItem()
{
	auto RecoveryItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// 移動速度＋方向
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 20.0f;

	RecoveryItem::create(RecoveryItemPos, inivelocity);
}

#include "VirusEnemyScript3-1.h"

#include "../../Explosion/Explosion.h"
#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "../../Item/CorePowerupItem/CorePowerupItem.h"
#include "../../Player/PlayerScript.h"
#include "../../Item/RecoveryItem/RecoveryItem.h"

VirusEnemyScript3_1::VirusEnemyScript3_1()
{
	timer = 0;	

	add_core_bullet = 0;

	// プレイヤーの位置を取得
	playerPos = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();

	playerFrag = true;

	counter = 0;
}

//毎フレーム呼ばれる
void VirusEnemyScript3_1::update()
{
	auto player = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER);

	if (playerFrag)
	{
		add_core_bullet = player.lock()->getComponent<PlayerScript>().lock()->add_core_bullet;
	}

	timer += TktkTime::deltaTime();

	Random::randomize();

	//移動
	move();

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

		GameObjectManager::sendMessage(DIE_Enemy3_1);
		getGameObject().lock()->destroy();
	}
}

//衝突開始で呼ばれる
void VirusEnemyScript3_1::onCollisionEnter(GameObjectPtr other)
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
void VirusEnemyScript3_1::onCollisionStay(GameObjectPtr other)
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
void VirusEnemyScript3_1::onCollisionExit(GameObjectPtr other)
{
}

void VirusEnemyScript3_1::handleMessage(int  eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
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
void VirusEnemyScript3_1::move()
{
	if (timer < 2.3f)
	{
		// 自身の回転角度
		float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

		// エネミーの位置を取得
		auto enemyPos = getComponent<Transform2D>().lock()->getWorldPosition();

		if (playerFrag)
		{
			// プレイヤーの位置を取得
			playerPos = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();
		}

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

void VirusEnemyScript3_1::PowerupItem()
{
	auto PowerupItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// 移動速度＋方向
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 20.0f;

	//パワーアップアイテム
	CorePowerupItem::create(PowerupItemPos, inivelocity);
}

void VirusEnemyScript3_1::RecoveryItem()
{
	auto RecoveryItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// 移動速度＋方向
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 20.0f;

	RecoveryItem::create(RecoveryItemPos, inivelocity);
}

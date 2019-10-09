#include "VirusEnemyScript4.h"

#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "VirusEnemy4.h"
#include "../../Item/CorePowerupItem/CorePowerupItem.h"
#include "../../Player/PlayerScript.h"
#include "../../Item/RecoveryItem/RecoveryItem.h"

VirusEnemyScript4::VirusEnemyScript4()
{
	timer = 0;

	add_core_bullet = 0;

	counter = 0;

	playerFrag = true;
}

//毎フレーム呼ばれてる
void VirusEnemyScript4::update()
{
	auto player = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER);

	if (playerFrag)
	{
		add_core_bullet = player.lock()->getComponent<PlayerScript>().lock()->add_core_bullet;
	}

	timer += TktkTime::deltaTime();

	//移動
	move();

	Random::randomize();

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

		GameObjectManager::sendMessage(DIE_Enemy4);
		getGameObject().lock()->destroy();
	}
}

//衝撃開始で呼ばれる
void VirusEnemyScript4::onCollisionEnter(GameObjectPtr other)
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
void VirusEnemyScript4::onCollisionStay(GameObjectPtr other)
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
void VirusEnemyScript4::onCollisionExit(GameObjectPtr other)
{
}

void VirusEnemyScript4::handleMessage(int  eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
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
void VirusEnemyScript4::move()
{
	// 自身の回転角度
	float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

	if (timer < 0.5f)
	{
		//プランナー、最後の数、変更可能
		auto velocity = Vector2(MathHelper::sin(345), MathHelper::cos(0)) * 50.0f;

		// 移動する
		getComponent<InertialMovement2D>().lock()->addForce(velocity);
	}
	else if (timer < 1.01f)
	{
		//プランナー、最後の数、変更可能
		auto velocity = Vector2(MathHelper::sin(195), MathHelper::cos(195)) * 50.0f;

		// 移動する
		getComponent<InertialMovement2D>().lock()->addForce(velocity);
	}
	else
	{
		timer = 0;
	}
}

void VirusEnemyScript4::PowerupItem()
{
	auto PowerupItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// 移動速度＋方向
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 20.0f;

	//パワーアップアイテム
	CorePowerupItem::create(PowerupItemPos, inivelocity);
}

void VirusEnemyScript4::RecoveryItem()
{
	auto RecoveryItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// 移動速度＋方向
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 20.0f;

	RecoveryItem::create(RecoveryItemPos, inivelocity);
}

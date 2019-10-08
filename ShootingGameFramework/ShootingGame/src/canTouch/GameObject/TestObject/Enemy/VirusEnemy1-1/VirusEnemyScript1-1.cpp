#include "VirusEnemyScript1-1.h"

#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "VirusEnemy1-1.h"
#include "../../Item/CorePowerupItem/CorePowerupItem.h"
#include "../../Player/PlayerScript.h"

VirusEnemyScript1_1::VirusEnemyScript1_1()
{
	timer = 0;

	add_core_bullet = 0;
}

//毎フレーム呼ばれてる
void VirusEnemyScript1_1::update()
{
	auto player = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER);

	add_core_bullet = player.lock()->getComponent<PlayerScript>().lock()->add_core_bullet;

	timer += TktkTime::deltaTime();

	//移動
	move();

	//体力が0以下になったら
	if (m_hp <= 0)
	{
		//`パワーアップアイテム
		PowerupItem();

		GameObjectManager::sendMessage(DIE_Enemy1_1);
		getGameObject().lock()->destroy();
	}
}

//衝撃開始で呼ばれる
void VirusEnemyScript1_1::onCollisionEnter(GameObjectPtr other)
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
void VirusEnemyScript1_1::onCollisionStay(GameObjectPtr other)
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
void VirusEnemyScript1_1::onCollisionExit(GameObjectPtr other)
{
}

void VirusEnemyScript1_1::handleMessage(int  eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

//移動
void VirusEnemyScript1_1::move()
{
	// 自身の回転角度
	float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

	if (timer < 2.5f)
	{
		//プランナー、最後の数、変更可能
		auto velocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 15.0f;

		// 移動する
		getComponent<InertialMovement2D>().lock()->addForce(velocity);
	}
	else if (timer < 5.3f)
	{
		auto velocity = Vector2(MathHelper::sin(420), MathHelper::cos(420)) * 15.0f;

		// 移動する
		getComponent<InertialMovement2D>().lock()->addForce(velocity);
	}
	else
	{
		auto velocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 15.0f;

		// 移動する
		getComponent<InertialMovement2D>().lock()->addForce(velocity);
	}
}

//パワーアップアイテムの出現
void VirusEnemyScript1_1::PowerupItem()
{
	auto PowerupItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// 移動速度＋方向
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 20.0f;

	//パワーアップアイテム
	CorePowerupItem::create(PowerupItemPos, inivelocity);
}

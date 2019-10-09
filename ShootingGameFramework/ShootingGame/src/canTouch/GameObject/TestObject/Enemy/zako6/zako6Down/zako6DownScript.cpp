#include "zako6DownScript.h"
#include "../../../Explosion_Enemy/Explosion_Enemy.h"
#include "../../../Item/CorePowerupItem/CorePowerupItem.h"
#include "../../../Item/RecoveryItem/RecoveryItem.h"
#include "../../../Player/PlayerScript.h"

zako6DownScript::zako6DownScript()
{
	add_core_bullet = 0;

	counter = 0;

	playerFrag = true;
}

void zako6DownScript::update()
{
	auto player = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER);

	if (playerFrag)
	{
		add_core_bullet = player.lock()->getComponent<PlayerScript>().lock()->add_core_bullet;
	}

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

		GameObjectManager::sendMessage(DIE_Enemy6);
		getGameObject().lock()->destroy();
	}
}

void zako6DownScript::onCollisionEnter(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_PLAYER_BULLET」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER || other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER_BULLET)
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

		// 体力を-3する
		m_hp -= 3;
	}

	//衝突相手のタグが「GAME_OBJECT_TAG_CORE」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_CORE)
	{
		// 爆発を生成する
		Explosion_Enemy::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		// 体力を-10する
		m_hp -= 10;
	}
}

void zako6DownScript::onCollisionStay(GameObjectPtr other)
{
}

void zako6DownScript::onCollisionExit(GameObjectPtr other)
{
}

void zako6DownScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	//もしゲームプレイオブジェクトが死ねといわれたら
	if (eventMessageType == DIE_GAMEPLAY_OBJECT || eventMessageType == DIE_BOSS3_DEAD)
	{
		//このコンポーネントが死ぬ
		getGameObject().lock()->destroy();
	}

	if (eventMessageType == DIE_PLAYER)
	{
		playerFrag = false;
	}
}

void zako6DownScript::onDestroy()
{	
}

void zako6DownScript::move()
{
	// 移動速度＋方向
	auto velocity = Vector2(MathHelper::sin(0), MathHelper::cos(0)) * 20.0f;


	// 移動する
	getComponent<InertialMovement2D>().lock()->addForce(velocity);
}

void zako6DownScript::PowerupItem()
{
	auto PowerupItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// 移動速度＋方向
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 100.0f;

	//パワーアップアイテム
	CorePowerupItem::create(PowerupItemPos, inivelocity);
}

void zako6DownScript::RecoveryItem()
{
	auto RecoveryItemPos = getComponent<Transform2D>().lock()->getWorldPosition();

	// 移動速度＋方向
	auto inivelocity = Vector2(MathHelper::sin(270), MathHelper::cos(270)) * 100.0f;

	RecoveryItem::create(RecoveryItemPos, inivelocity);
}

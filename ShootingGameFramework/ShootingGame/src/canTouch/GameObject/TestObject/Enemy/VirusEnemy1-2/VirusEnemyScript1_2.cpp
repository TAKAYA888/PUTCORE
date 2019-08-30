#include "VirusEnemyScript1-2.h"

#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "VirusEnemy1-2.h"

VirusEnemyScript1_2::VirusEnemyScript1_2()
{
	timer = 0;
}

//毎フレーム呼ばれる
void VirusEnemyScript1_2::update()
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
void VirusEnemyScript1_2::onCollisionEnter(GameObjectPtr other)
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
void VirusEnemyScript1_2::onCollisionStay(GameObjectPtr other)
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

//衝突終了で呼ばれます
void VirusEnemyScript1_2::onCollisionExit(GameObjectPtr other)
{
}

void VirusEnemyScript1_2::handleMessage(int  eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}
//移動
void VirusEnemyScript1_2::move()
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
		auto velocity = Vector2(MathHelper::sin(120), MathHelper::cos(120)) * 15.0f;

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
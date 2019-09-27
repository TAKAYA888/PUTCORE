#include "zako6DownScript.h"
#include "../../../Explosion_Enemy/Explosion_Enemy.h"

zako6DownScript::zako6DownScript()
{

}

void zako6DownScript::update()
{
	move();

	//体力が0以下になったら
	if (m_hp <= 0)
	{
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
}

void zako6DownScript::onDestroy()
{
	//死んだときにこのメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_Enemy6);
}

void zako6DownScript::move()
{
	// 移動速度＋方向
	auto velocity = Vector2(MathHelper::sin(0), MathHelper::cos(0)) * 20.0f;


	// 移動する
	getComponent<InertialMovement2D>().lock()->addForce(velocity);
}
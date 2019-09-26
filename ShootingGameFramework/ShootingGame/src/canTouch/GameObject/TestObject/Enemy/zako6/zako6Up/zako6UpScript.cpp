#include "zako6UpScript.h"
#include "../../../Explosion_Enemy/Explosion_Enemy.h"

zako6UpScript::zako6UpScript()
{

}

void zako6UpScript::update()
{
	move();
}

void zako6UpScript::onCollisionEnter(GameObjectPtr other)
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
}

void zako6UpScript::onCollisionStay(GameObjectPtr other)
{
}

void zako6UpScript::onCollisionExit(GameObjectPtr other)
{
}

void zako6UpScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	//もしゲームプレイオブジェクトが死ねといわれたら
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		//このコンポーネントが死ぬ
		getGameObject().lock()->destroy();
	}
}

void zako6UpScript::onDestroy()
{
	//死んだときにこのメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_Enemy6);
}

void zako6UpScript::move()
{
	// 移動速度＋方向
	auto velocity = Vector2(MathHelper::sin(180), MathHelper::cos(180)) * 20.0f;


	// 移動する
	getComponent<InertialMovement2D>().lock()->addForce(velocity);
}


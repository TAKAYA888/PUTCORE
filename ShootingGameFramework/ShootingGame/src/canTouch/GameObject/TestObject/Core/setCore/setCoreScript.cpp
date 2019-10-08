#include "setCoreScript.h"

#include "../StayCore/CoreScript.h"
#include "../../../TestObject/PlayerBullet/PlayerBullet.h"
#include "../../../TestObject/CoreBullet/CoreBullet.h"

#include "../../Explosion/Explosion.h"

#include <iostream>


setCoreScript::setCoreScript()
{
	counter = 0;
	coolTime = 0.5f;
}

void setCoreScript::update()
{
	bool curActiveFlag = getComponent<CoreScript>().lock()->isActive();
	Vector2 Postion = getComponent<Transform2D>().lock()->getWorldPosition();

	counter += TktkTime::deltaTime();

	if (curActiveFlag)
	{
		getComponent<setCoreScript>().lock()->setActive(false);
	}

	//当たり判定を付ける
	getComponent<RectCollider>().lock()->setActive(true);
	//当たり判定を描画付ける
	//getComponent<RectColliderWireFrameDrawer>().lock()->setActive(true);

	if (counter >= 5)
	{
		//移動する処理	
		// 移動速度＋方向
		auto velocity = Vector2(MathHelper::sin(90), MathHelper::cos(90)) * 100.0f;

		// 移動する
		getComponent<InertialMovement2D>().lock()->addForce(velocity);
		//アニメーションを止める
		getComponent<AnimatedSprite2d>().lock()->setAnimSpeedRate(0);
	}
	else
	{
		if (coolTime < 0)
		{
			// 弾の初期速度
			auto initVelocity1 = Vector2(MathHelper::sin(90), -MathHelper::cos(90)) * 512.0f;
			auto initVelocity2 = Vector2(MathHelper::sin(70), -MathHelper::cos(70)) * 512.0f;
			auto initVelocity3 = Vector2(MathHelper::sin(110), -MathHelper::cos(110)) * 512.0f;
			CoreBullet::create(Postion, initVelocity1);
			CoreBullet::create(Postion, initVelocity2);
			CoreBullet::create(Postion, initVelocity3);

			coolTime += 0.5f;
		}
		else
		{
			coolTime -= TktkTime::deltaTime();
		}
		getComponent<AnimatedSprite2d>().lock()->setAnimSpeedRate(-2);
	}


	//画面外にでたら消去する	
	if (Postion.x > 1400)
	{
		getGameObject().lock()->destroy();
		counter = 0;
	}
}

void setCoreScript::onCollisionEnter(GameObjectPtr other)
{
	std::cout << other.lock()->getTag();

	// 衝突相手のタグが「GAME_OBJECT_TAG_ENEMY_BULLET」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY_BULLET || other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY || other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY_BOSS)
	{
		// 爆発を生成する
		Explosion::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		getGameObject().lock()->destroy();
		counter = 0;
	}
}

void setCoreScript::onCollisionStay(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_ENEMY_BULLET」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY_BULLET || other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY || other.lock()->getTag() == GAME_OBJECT_TAG_ENEMY_BOSS)
	{
		// 爆発を生成する
		Explosion::create(
			other.lock()->getComponent<Transform2D>().lock()->getWorldPosition()
		);

		getComponent<CoreScript>().lock()->setActive(true);
		counter = 0;
	}
}

void setCoreScript::onCollisionExit(GameObjectPtr other)
{
}

void setCoreScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

void setCoreScript::onDestroy()
{
	//死んだときにこのメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_CORE);
}

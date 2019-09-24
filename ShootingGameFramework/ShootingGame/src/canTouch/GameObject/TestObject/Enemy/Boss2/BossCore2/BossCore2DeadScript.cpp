#include "BossCore2DeadScript.h"
#include "BossCore2Script.h"
#include "../../../Explosion_Enemy/Explosion_Enemy.h"

BossCore2DeadScript::BossCore2DeadScript()
{
	timer = 0;
}

void BossCore2DeadScript::update()
{
	timer += TktkTime::deltaTime();
	bool ActivFlag = getComponent<BossCore2Script>().lock()->isActive();
	if (ActivFlag == false)
	{
		getComponent<RectCollider>().lock()->setActive(false);
		getComponent<RectColliderWireFrameDrawer>().lock()->setActive(false);
		getComponent<Sprite2dDrawer>().lock()->setActive(false);
		getComponent<AnimatedSprite2d>().lock()->setActive(false);
	}

	if (timer > 15)
	{
		getComponent<BossCore2Script>().lock()->setActive(true);
		getComponent<RectCollider>().lock()->setActive(true);
		getComponent<RectColliderWireFrameDrawer>().lock()->setActive(true);
		getComponent<Sprite2dDrawer>().lock()->setActive(true);
		getComponent<AnimatedSprite2d>().lock()->setActive(true);
		timer = 0;
	}
}

void BossCore2DeadScript::onCollisionEnter(GameObjectPtr other)
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
}

void BossCore2DeadScript::onCollisionStay(GameObjectPtr other)
{
}

void BossCore2DeadScript::onCollisionExit(GameObjectPtr other)
{
}

void BossCore2DeadScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	//もしゲームプレイオブジェクトが死ねといわれたら
	if (eventMessageType == DIE_BOSS2_DEAD)
	{
		//このコンポーネントが死ぬ
		getGameObject().lock()->destroy();
	}
}

void BossCore2DeadScript::onDestroy()
{
}
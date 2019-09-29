#include "BossCoreDeadScript.h"
#include "BossCoreScript.h"
#include "../../../Explosion_Enemy/Explosion_Enemy.h"

BossCoreDeadScript::BossCoreDeadScript()
{
	timer = 0;
}

void BossCoreDeadScript::update()
{
	//カウントアップ
	timer += TktkTime::deltaTime();
	//bossCore１のスクリプトがオンになっているか受け取る
	bool ActivFlag = getComponent<BossCore1Script>().lock()->isActive();
	//もしbossCore１のスクリプトがfalseなら
	if (ActivFlag == false)
	{
		//当たり判定、当たり判定の描画、画像の描画、アニメーションのコンポーネントをfalseにする
		getComponent<RectCollider>().lock()->setActive(false);
		getComponent<RectColliderWireFrameDrawer>().lock()->setActive(false);
		getComponent<Sprite2dDrawer>().lock()->setActive(false);
		getComponent<AnimatedSprite2d>().lock()->setActive(false);
	}

	//もしこのスクリプトが起動して15秒以上経過したら
	if (timer > 15)
	{
		//当たり判定、当たり判定の描画、画像の描画、アニメーションのコンポーネントをtrueにする
		getComponent<BossCore1Script>().lock()->setActive(true);
		getComponent<RectCollider>().lock()->setActive(true);
		getComponent<RectColliderWireFrameDrawer>().lock()->setActive(true);
		getComponent<Sprite2dDrawer>().lock()->setActive(true);
		getComponent<AnimatedSprite2d>().lock()->setActive(true);
		//タイマーのリセット
		timer = 0;
	}
}

void BossCoreDeadScript::onCollisionEnter(GameObjectPtr other)
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

void BossCoreDeadScript::onCollisionStay(GameObjectPtr other)
{
}

void BossCoreDeadScript::onCollisionExit(GameObjectPtr other)
{
}

void BossCoreDeadScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	//もしゲームプレイオブジェクトが死ねといわれたら
	if (eventMessageType == DIE_BOSS2_DEAD)
	{
		//このコンポーネントが死ぬ
		getGameObject().lock()->destroy();
	}
}

void BossCoreDeadScript::onDestroy()
{
}


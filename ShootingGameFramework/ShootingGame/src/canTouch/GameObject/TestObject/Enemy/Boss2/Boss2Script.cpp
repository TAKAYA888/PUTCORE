#include "Boss2Script.h"
#include "BossCore1/BossCore1.h"
#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "BossCore2/BossCore2.h"
#include "../../EnemyBullet/VirusEnemyBullet/VirusEnemyBullet.h"
#include "../Boss/BossDead/BossDead.h"

Boss2Script::Boss2Script()
{
	timer = 0;
	//bossコア１の生成
	BossCore1::create(Vector2(1450, 400), 0);
	//bossコア２の生成
	BossCore2::create(Vector2(1450, 700), 0);
}

void Boss2Script::update()
{
	//タイマーのカウントアップ
	timer += TktkTime::deltaTime();
	//現在の座標を受け取る
	Vector2 nowPos = getComponent<Transform2D>().lock()->getLocalPosition();
	//もし15.5秒以上経過したら
	if (timer > 15.5f)
	{
		//5回弾を生成する
		for (float i = 0; i <= 60; i += 15)
		{
			//向きと速度の設定
			auto initVelocity1 = Vector2(MathHelper::sin(240.0f + i), MathHelper::cos(240.0f + i)) * 512.0f;
			//弾の生成
			VirusEnemyBullet::create(nowPos, initVelocity1);
			//弾発射のSE
			getComponent<SePlayer>().lock()->playSe();
		}
		//タイマーのリセット
		timer = 0;
	}

	//もしHpが0以下になったら
	if (m_hp <= 0)
	{
		BossDead::create(getComponent<Transform2D>().lock()->getWorldPosition());
		// 自分を殺す
		getGameObject().lock()->destroy();
	}
}

void Boss2Script::onCollisionEnter(GameObjectPtr other)
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

void Boss2Script::onCollisionStay(GameObjectPtr other)
{
}

void Boss2Script::onCollisionExit(GameObjectPtr other)
{
}

void Boss2Script::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	//もしゲームプレイオブジェクトが死ねといわれたら
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		//このコンポーネントが死ぬ
		getGameObject().lock()->destroy();
	}
}

void Boss2Script::onDestroy()
{
	//死んだときにこのメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_BOSS2_DEAD);
}

void Boss2Script::Shot()
{
}


#include "BossCoreScript.h"
#include "BossCoreDeadScript.h"
#include "../../../Explosion_Enemy/Explosion_Enemy.h"
#include "../../../EnemyBullet/VirusEnemyBullet/VirusEnemyBullet.h"
#include <string>
#include<iostream>

BossCore1Script::BossCore1Script()
{
	timer = 0;
	angle = 0;
	shotfrag = true;
}

void BossCore1Script::update()
{
	//このスクリプトのActiveフラグを受け取る
	bool ActiveFrag = getComponent<BossCore1Script>().lock()->isActive();
	//もしActiveフラグがtrueなら
	if (ActiveFrag)
	{
		//下記のコンポーネントをfalseにする
		getComponent<BossCoreDeadScript>().lock()->setActive(false);
	}

	//もしHpが0以下なら
	if (m_hp <= 0)
	{
		//下記のコンポーネントをtrueにする
		getComponent<BossCoreDeadScript>().lock()->setActive(true);
		//下記のコンポーネントをfalseにする
		getComponent<BossCore1Script>().lock()->setActive(false);
		//Hpを15にする
		m_hp = 15;
	}

	//シュートタイマーをカウントダウンする
	m_shotTimer -= TktkTime::deltaTime();
	//シュートタイマーを-10以下にならないようにする
	if (m_shotTimer < -10.0f)
	{
		m_shotTimer = 0.0f;
	}
	//タイマーをカウントアップする
	timer += TktkTime::deltaTime();
	//現在の座標を受け取る
	Vector2 nowPos = getComponent<Transform2D>().lock()->getLocalPosition();
	//タイマーが5秒以上になったら
	if (timer < 5.0f)
	{
		//角度を変える
		angle += TktkTime::deltaTime() * 10;
	}
	else if (timer < 15.0f)
	{
		//角度を変える
		angle -= TktkTime::deltaTime() * 10;
	}
	else if (timer < 20.5f)
	{
		//ショットフラグをfalseにする
		shotfrag = false;
	}
	else
	{
		angle = 0;
		timer = 0;
		shotfrag = true;
	}

	//速度と角度を設定する
	auto initVelocity1 = Vector2(MathHelper::sin(250.0f + angle), MathHelper::cos(250.0f + angle)) * 512.0f;
	auto initVelocity2 = Vector2(MathHelper::sin(280.0f + angle), MathHelper::cos(280.0f + angle)) * 512.0f;

	//弾を撃つ
	if (m_shotTimer < 0.0f && shotfrag)
	{
		VirusEnemyBullet::create(nowPos, initVelocity1);
		VirusEnemyBullet::create(nowPos, initVelocity2);
		m_shotTimer = 0.5f;
		//弾発射のSE
		getComponent<SePlayer>().lock()->playSe();
	}
}

void BossCore1Script::onCollisionEnter(GameObjectPtr other)
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

void BossCore1Script::onCollisionStay(GameObjectPtr other)
{
}

void BossCore1Script::onCollisionExit(GameObjectPtr other)
{
}

void BossCore1Script::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	//もしゲームプレイオブジェクトが死ねといわれたら
	if (eventMessageType == DIE_BOSS2_DEAD)
	{
		//このコンポーネントが死ぬ
		getGameObject().lock()->destroy();
	}
}

void BossCore1Script::onDestroy()
{
}

void BossCore1Script::Shot()
{
}
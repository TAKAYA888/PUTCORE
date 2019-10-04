#include "BossScript.h"

#include "../../EnemyBullet/EnemyNormalBullet/EnemyNormalBullet.h"
#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "BossTeleportation/BossTeleportation.h"
#include "BossDead/BossDead.h"

BossScript::BossScript()
{
	timer = 0;
	counter = 0;
	teleportionCounter = true;
}

void BossScript::update()
{
	//カウントアップ　移動と発射のタイミング
	timer += TktkTime::deltaTime();
	//もしステータスが普通なら
	if (m_curState == State::normal)
	{
		//発射と移動の処理そしてタイマーのリセット
		if (timer > 1.94f && teleportionCounter)
		{
			BossTeleportation::create(getComponent<Transform2D>().lock()->getWorldPosition());
			teleportionCounter = false;
		}
		else if (timer > 2.0f)
		{
			Shot();

			move();

			timer = 0;

			teleportionCounter = true;
		}

		//もしHPが50を下回ったら
		if (m_hp <= 50)
		{
			//アニメーションのコンポーネントをオフにする
			getComponent<AnimatedSprite2d>().lock()->setActive(false);
			//気絶時の画像に差し替える
			getComponent<Sprite2dDrawer>().lock()->setSpriteId(IMAGE_ENEMY_BOSS_FAINT);
			//タイマーをリセットする
			timer = 0;
			counter = 0;
			//ステータスを昏倒じょうたいにする
			changeState(faint);
		}
	}
	//もしステータスが昏倒なら
	else if (m_curState == State::faint)
	{
		//もしタイマーが2秒以上経過したら
		if (timer > 2.0f)
		{
			//ステータスを怒り状態にする
			changeState(angry);
			//アニメのコンポーネントをオンにする
			getComponent<AnimatedSprite2d>().lock()->setActive(true);
			//描画のIDをBOSS1にもどす　　必要かわからないのでいらなそうなら消しても問題ない
			getComponent<Sprite2dDrawer>().lock()->setSpriteId(IMAGE_ENEMY_BOSS_1);
		}
	}
	else if (m_curState == State::angry)
	{
		//もしカウンターが3以下なら
		if (counter < 3.0f)
		{
			//もしタイマーが一秒以上なら
			if (timer > 0.96f && teleportionCounter)
			{
				BossTeleportation::create(getComponent<Transform2D>().lock()->getWorldPosition());
				teleportionCounter = false;
			}
			if (timer > 1.0f)
			{
				Shot();

				move();

				timer = 0;
				//カウントアップ
				counter += 1;

				teleportionCounter = true;
			}

		}
		//3以上なら
		else
		{
			if (timer > 2.96f && teleportionCounter)
			{
				BossTeleportation::create(getComponent<Transform2D>().lock()->getWorldPosition());
				teleportionCounter = false;
			}
			else if (timer > 3)
			{
				Shot();

				move();

				timer = 0;
				//カウンターリセット
				counter = 0;
				teleportionCounter = true;
			}
		}
	}

	if (m_hp <= 0)
	{
		////ゲームクリアシーンに移行する
		//SceneManager::changeScene(CLEAR_SCENE);
		BossDead::create(getComponent<Transform2D>().lock()->getWorldPosition());
		changeState(dying);
		// 自分を殺す
		getGameObject().lock()->destroy();
	}
}

void BossScript::onCollisionEnter(GameObjectPtr other)
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

void BossScript::onCollisionStay(GameObjectPtr other)
{
}

void BossScript::onCollisionExit(GameObjectPtr other)
{
}

void BossScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	//もしゲームプレイオブジェクトが死ねといわれたら
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		//このコンポーネントが死ぬ
		getGameObject().lock()->destroy();
	}
}

void BossScript::onDestroy()
{
	GameObjectManager::sendMessage(DIE_BOSS1_DEAD);
}

//ステータスの変更を行う
void BossScript::changeState(State nextState)
{
	m_curState = nextState;
}

void BossScript::move()
{
	//xを500、1100の間でランダムに移動する
	float x = Random::getRandF(500, 1100);
	//yを128、600の間でランダムに移動する
	float y = Random::getRandF(128, 600);

	getComponent<Transform2D>().lock()->setLocalPosition(Vector2(x, y));
}

void BossScript::Shot()
{
	// 弾の出現座標
	Vector2 spawnPos = getComponent<Transform2D>().lock()->getWorldPosition();

	//弾のスポーン位置をずらす
	spawnPos;
	spawnPos.x = spawnPos.x - 45.0f;
	spawnPos.y = spawnPos.y + 15.0f;

	for (float i = 0; i < 12; i++)
	{
		// 自身の回転角度
		float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

		// 弾の初期速度
		auto initVelocity = Vector2(MathHelper::sin(30.0f * i), MathHelper::cos(30.0f * i)) * 512.0f;

		// 敵の通常弾を出現
		EnemyNormalBullet::create(spawnPos, initVelocity);
	}
}
#include "Boss3Script.h"
#include "../../EnemyBullet/EnemyNormalBullet/EnemyNormalBullet.h"
#include "../../Enemy/Boss/BossTeleportation/BossTeleportation.h"
#include "../../Enemy/zako6/zako6Up/zako6Up.h"
#include "../../Enemy/zako6/zako6Down/zako6Down.h"
#include "../../Explosion_Enemy/Explosion_Enemy.h"
#include "../../Enemy/Boss/BossDead/BossDead.h"

Boss3Script::Boss3Script()
{
	timer = 0;
	Vector2 playerPos = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();

	PlayerFrag = true;
	ShotFrag1 = true;
	ShotFrag2 = true;
}

void Boss3Script::update()
{
	timer += TktkTime::deltaTime();

	if (ActionCounter < 4)
	{
		if (timer > 1 && ShotFrag1)
		{
			Shot1();

			ShotFrag1 = false;
		}
		else if (timer > 1.5 && ShotFrag2)
		{
			Shot2();

			ShotFrag2 = false;
		}
		else if (timer > 3)
		{
			ActionCounter++;

			ShotFrag1 = true;
			ShotFrag2 = true;

			Move();

			timer = 0;
		}
	}
	else
	{
		if (timer > 1 && EnemyFrag[0])
		{
			zako6Up::create(Vector2(600, 700), 0);
			zako6Down::create(Vector2(400, 0), 0);
			EnemyFrag[0] = false;
		}
		else if (timer > 1.5&&EnemyFrag[1])
		{
			zako6Up::create(Vector2(600, 700), 0);
			zako6Down::create(Vector2(400, 0), 0);
			EnemyFrag[1] = false;
		}
		else if (timer > 2 && EnemyFrag[2])
		{
			zako6Up::create(Vector2(600, 700), 0);
			zako6Down::create(Vector2(400, 0), 0);
			EnemyFrag[2] = false;
		}
		else if (timer > 4.5 && EnemyFrag2[0])
		{
			zako6Up::create(Vector2(400, 700), 0);
			zako6Down::create(Vector2(600, 0), 0);
			EnemyFrag2[0] = false;
		}
		else if (timer > 5 && EnemyFrag2[1])
		{
			zako6Up::create(Vector2(400, 700), 0);
			zako6Down::create(Vector2(600, 0), 0);
			EnemyFrag2[1] = false;
		}
		else if (timer > 5.5 && EnemyFrag2[2])
		{
			zako6Up::create(Vector2(400, 700), 0);
			zako6Down::create(Vector2(600, 0), 0);
			EnemyFrag2[2] = false;
		}
		else if (timer > 8 && EnemyFrag3[0])
		{
			zako6Up::create(Vector2(500, 700), 0);
			zako6Down::create(Vector2(300, 0), 0);
			EnemyFrag3[0] = false;
		}
		else if (timer > 8.5 && EnemyFrag3[1])
		{
			zako6Up::create(Vector2(500, 700), 0);
			zako6Down::create(Vector2(300, 0), 0);
			EnemyFrag3[1] = false;
		}
		else if (timer > 9 && EnemyFrag3[2])
		{
			zako6Up::create(Vector2(500, 700), 0);
			zako6Down::create(Vector2(300, 0), 0);
			EnemyFrag3[2] = false;
		}
		else if (timer > 11.5&&EnemyFrag4[0])
		{
			zako6Up::create(Vector2(300, 700), 0);
			zako6Down::create(Vector2(500, 0), 0);
			EnemyFrag4[0] = false;
		}
		else if (timer > 12 && EnemyFrag4[1])
		{
			zako6Up::create(Vector2(300, 700), 0);
			zako6Down::create(Vector2(500, 0), 0);
			EnemyFrag4[1] = false;
		}
		else if (timer > 12.5&&EnemyFrag4[2])
		{
			zako6Up::create(Vector2(300, 700), 0);
			zako6Down::create(Vector2(500, 0), 0);
			EnemyFrag4[2] = false;
		}
		else if (timer > 13)
		{
			ActionCounter = 0;
			for (size_t i = 0; i < 3; i++)
			{
				EnemyFrag[i] = true;
				EnemyFrag2[i] = true;
				EnemyFrag3[i] = true;
				EnemyFrag4[i] = true;
			}
			timer = 0;
		}
	}

	//もしHpが0以下になったら
	if (m_hp <= 0)
	{
		BossDead::create(getComponent<Transform2D>().lock()->getWorldPosition());
		GameObjectManager::sendMessage(DIE_BOSS3_DEAD);
		// 自分を殺す
		getGameObject().lock()->destroy();
	}
}

void Boss3Script::onCollisionEnter(GameObjectPtr other)
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

void Boss3Script::onCollisionStay(GameObjectPtr other)
{
}

void Boss3Script::onCollisionExit(GameObjectPtr other)
{
}

void Boss3Script::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_PLAYER)
	{
		PlayerFrag = false;
	}

	//もしゲームプレイオブジェクトが死ねといわれたら
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		//このコンポーネントが死ぬ
		getGameObject().lock()->destroy();
	}
}

void Boss3Script::onDestroy()
{
}

void Boss3Script::Shot1()
{
	//自身の位置を取得する
	Vector2 Boss3Pos = getComponent<Transform2D>().lock()->getWorldPosition();

	if (PlayerFrag)
	{
		// プレイヤーの位置を取得
		playerPos = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();
	}

	// 「プレイヤー」->「エネミー」のベクトルを求める
	auto enemyToMouse = playerPos - Boss3Pos;

	// ２つのベクトルの外積を求める
	float cross = Vector2::cross(enemyToMouse, Vector2::down);

	// ２つのベクトルの内積を求める
	float dot = Vector2::dot(enemyToMouse, Vector2::down);

	// 逆タンジェントを使って向きたい角度を求める
	float result = MathHelper::atan(cross, dot);

	for (size_t i = 0; i < 5; i++)
	{
		// 弾の初期速度
		auto initVelocity = Vector2(MathHelper::sin(result + shotAngle1[i] + 180), MathHelper::cos(result + shotAngle1[i] + 180)) * 512.0f;

		EnemyNormalBullet::create(Boss3Pos, initVelocity);
	}
}

void Boss3Script::Shot2()
{
	//自身の位置を取得する
	Vector2 Boss3Pos = getComponent<Transform2D>().lock()->getWorldPosition();

	if (PlayerFrag)
	{
		// プレイヤーの位置を取得
		playerPos = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<Transform2D>().lock()->getWorldPosition();
	}

	// 「プレイヤー」->「エネミー」のベクトルを求める
	auto enemyToMouse = playerPos - Boss3Pos;

	// ２つのベクトルの外積を求める
	float cross = Vector2::cross(enemyToMouse, Vector2::down);

	// ２つのベクトルの内積を求める
	float dot = Vector2::dot(enemyToMouse, Vector2::down);

	// 逆タンジェントを使って向きたい角度を求める
	float result = MathHelper::atan(cross, dot);

	for (size_t i = 0; i < 4; i++)
	{
		// 弾の初期速度
		auto initVelocity = Vector2(MathHelper::sin(result + shotAngle2[i] + 180), MathHelper::cos(result + shotAngle2[i] + 180)) * 512.0f;

		EnemyNormalBullet::create(Boss3Pos, initVelocity);
	}
}

void Boss3Script::Move()
{
	//xを500、1100の間でランダムに移動する
	float x = Random::getRandF(600, 1280);
	//yを128、600の間でランダムに移動する
	float y = Random::getRandF(0, 760);

	BossTeleportation::create(Vector2(x, y));

	getComponent<Transform2D>().lock()->setLocalPosition(Vector2(x, y));
}
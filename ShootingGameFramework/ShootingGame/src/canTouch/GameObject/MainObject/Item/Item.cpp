#include "ItemScript.h"

ItemScript::ItemScript()
{
}

// 毎フレーム呼ばれる
void ItemScript::update()
{
	// 移動
	move();
	
	

	// 体力が０以下になったら
	if (m_hp <= 0)
	{
		getComponent<SePlayer>().lock()->playSe();
		// 自分を殺す
		getGameObject().lock()->destroy();
	}
}

// 衝突開始で呼ばれる
void ItemScript::onCollisionEnter(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_PLAYER_BULLET」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER_BULLET)
	{
	
	

		// 体力を-1する
		m_hp--;
	}
}

// 衝突中で呼ばれる
void ItemScript::onCollisionStay(GameObjectPtr other)
{
	// 衝突相手のタグが「GAME_OBJECT_TAG_PLAYER」だったら
	if (other.lock()->getTag() == GAME_OBJECT_TAG_PLAYER)
	{
		
		// 体力を-1する
		m_hp--;
	}
}

// 衝突終了で呼ばれる
void ItemScript::onCollisionExit(GameObjectPtr other)
{
}

void ItemScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

// 移動
void ItemScript::move()
{
	// 自身の回転角度
	float rotationDeg = getComponent<Transform2D>().lock()->getWorldRotationDeg();

	// 移動速度＋方向
	auto velocity = Vector2(MathHelper::sin(rotationDeg), -MathHelper::cos(rotationDeg)) * 20.0f;


	// 移動する
	getComponent<InertialMovement2D>().lock()->addForce(velocity);
}



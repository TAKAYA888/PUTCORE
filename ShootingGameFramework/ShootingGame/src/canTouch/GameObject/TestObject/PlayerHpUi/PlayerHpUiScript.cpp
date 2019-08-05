#include "PlayerHpUiScript.h"

#include "../Player/PlayerScript.h"

PlayerHpUiScript::PlayerHpUiScript(float hpGaugeWidth)
	: m_hpGaugeWidth(hpGaugeWidth)
{
}

void PlayerHpUiScript::update()
{
	// 最大HPと現在のHPの比率を取得
	float playerHpRate = calculateHpRate();

	// 自分のトランスフォーム2Dを取得
	auto transform2D = getComponent<Transform2D>();

	// 自身のx方向のスケールを「HPの比率*ゲージの長さ」にする
	transform2D.lock()->setLocalScaleRate(Vector2(playerHpRate * m_hpGaugeWidth, 1.0f));
}

void PlayerHpUiScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

// 最大HPと現在のHPの比率を計算する
float PlayerHpUiScript::calculateHpRate()
{
	// プレイヤーのポインタが空だったら
	if (m_player.expired())
	{
		// プレイヤーのタグを持っているゲームオブジェクトを取得
		m_player = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER);

		// 取得できなければ0.0fを返す
		if (m_player.expired()) return 0.0f;
	}

	// プレイヤーからプレイヤースクリプトを取得
	auto playerScript = m_player.lock()->getComponent<PlayerScript>();

	// 取得できなければ0.0fを返す
	if (playerScript.expired()) return 0.0f;

	// 最大HPと現在のHPの割合を返す
	return static_cast<float>(playerScript.lock()->getCurHp()) / playerScript.lock()->getMaxHp();
}

#include "GameEndCheckerScript.h"

GameEndCheckerScript::GameEndCheckerScript()
{
}

// 毎フレーム呼ばれる
void GameEndCheckerScript::update()
{
	// ゲーム終了フラグが立っていたら
	if (m_gameEnd)
	{
		// シーンが切り替わるまでのタイマーを更新
		m_sceneChangeTimer -= TktkTime::deltaTime();

		// タイマーが０以下になったら
		if (m_sceneChangeTimer < 0.0f)
		{
			// タイトルシーンに移行する
			SceneManager::changeScene(TITLE_SCENE);
		}
		return;
	}

	// 「GAME_OBJECT_TAG_PLAYER」のタグを持っているゲームオブジェクトを探す
	auto player = GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER);

	// ゲーム開始検知フラグが立っていなければ
	if (!m_gameStart)
	{
		// プレイヤーの存在が確認出来たら、ゲーム開始検知フラグを立てる
		if (!player.expired()) m_gameStart = true;

		return;
	}

	// プレイヤーが見つからなかったら（死んでいたら）
	if (player.expired())
	{
		// 時間の経過速度を1/5にする
		TktkTime::setTimeScale(0.2f);

		// ゲーム終了フラグを立てる
		m_gameEnd = true;
	}

	// ボスを既定数倒したら
	if (m_bossKillCount >= m_bossKillTargetValue)
	{
		// 時間の経過速度を1/5にする
		TktkTime::setTimeScale(0.2f);

		// ゲーム終了フラグを立てる
		m_gameEnd = true;
	}
}

// メッセージ受信時に呼ばれる
void GameEndCheckerScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	// 受け取ったメッセージが「ENEMY_BOSS_DEAD」だったら
	if (eventMessageType == ENEMY_BOSS_DEAD)
	{
		// ボスを倒した数を+1する
		m_bossKillCount++;
	}

	// 受け取ったメッセージが「DIE_GAMEPLAY_OBJECT」だったら
	if (eventMessageType == DIE_GAMEPLAY_OBJECT)
	{
		// 自身を殺す
		getGameObject().lock()->destroy();
	}
}

// 消える直前に呼ばれる
void GameEndCheckerScript::onDestroy()
{
	// 時間の経過速度を等倍にする
	TktkTime::setTimeScale(1.0f);
}
#include "Main2Scene.h"

#include "../GameObject/TestObject/Core/StayCore/Core.h"
#include "../GameObject/TestObject/BackGround/BackGround2/BackGround_2.h"
#include "../GameObject/PauseObject/PauseLogo/PauseLogo.h"
#include "../GameObject/PauseObject/RestartButton/RestartButton.h"
#include "../GameObject/TestObject/Player/Player.h"
#include "../GameObject/TestObject/EnemyGenerator2/EnemyGenerator2.h"
#include "../GameObject/TestObject/PlayerHpUi/PlayerHpUi.h"
#include "../GameObject/TestObject/GameEndChecker/GameEndChecker.h"

#include "../GameObject/TestObject/AnimSample/AnimSample.h"
#include "../GameObject/TestObject/GamePlayBgmPlayer/GamePlayBgmPlayer.h"



Main2Scene::Main2Scene()
{
}

// シーンの開始時に呼ばれる
void Main2Scene::start()
{
	//背景2を生成する
	BackGround_2::create(Vector2::zero);
	BackGround_2::create(Vector2(SCREEN_SIZE_X, 0));

	// プレイヤーを生成する
	Player::create(SCREEN_SIZE / 2);

	//コアを生成する
	Core::create(SCREEN_SIZE / 2);

	// プレイヤーのHPゲージを生成する
	PlayerHpUi::create(Vector2(20.0f, SCREEN_SIZE_Y - 30.0f));

	// エネミージェネレーターを生成する
	EnemyGenerator2::create();

	// ゲーム終了条件を判定するクラスを生成する
	GameEndChecker::create();

	// アニメーションサンプルを生成
	AnimSample::create(Vector2(SCREEN_SIZE.x / 2, 32.0f));

	// ゲームプレイ用のBGMプレイヤーを生成
	GamePlayBgmPlayer::create();


}

// 毎フレーム呼ばれる
void Main2Scene::update()
{
	

	if (Keyboard::getState(InputType::INPUT_ENDED, KeyboardKeyType::KEYBOARD_TAB) || GamePad::getState(GamePadNumber::GAME_PAD_NUMBER_1, InputType::INPUT_BEGIN, GamePadButtonType::GAME_PAD_START_BUTTON))
	{
		float TimeScale = 0.0f;
		TimeScale = TktkTime::getTimeScale();
		if (TimeScale >= 0.9f)
		{
			// 時間の経過速度を0にする
			TktkTime::setTimeScale(0.0f);
			// PlayerScriptを無効化
			GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<PlayerScript>().lock()->setActive(false);
			//ポーズ画面をクリエイトする
			RestartButton::create(SCREEN_SIZE.x / 1);
			PauseLogo::create();
		}
		else
		{
			//ポーズ終了のアナウンス
			GameObjectManager::sendMessage(PAUSE_END);
			// 時間の経過速度を1にする
			GameObjectManager::findGameObjectWithTag(GAME_OBJECT_TAG_PLAYER).lock()->getComponent<PlayerScript>().lock()->setActive(true);
			// PlayerScriptを有効化
			TktkTime::setTimeScale(1.0f);
		}
	}
}

// シーンの終了時に呼ばれる
void Main2Scene::end()
{
	// 全てのゲームオブジェクトに「DIE_GAMEPLAY_OBJECT」のメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_GAMEPLAY_OBJECT);
}

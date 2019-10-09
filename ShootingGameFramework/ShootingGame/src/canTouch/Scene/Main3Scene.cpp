#include "Main3Scene.h"

#include "../GameObject/TestObject/Core/StayCore/Core.h"
#include "../GameObject/TestObject/BackGround/BackGround3/BackGround_3.h"
#include "../GameObject/PauseObject/PauseLogo/PauseLogo.h"
#include "../GameObject/PauseObject/RestartButton/RestartButton.h"
#include "../GameObject/TestObject/Player/Player.h"
#include "../GameObject/TestObject/EnemyGenerator3/EnemyGenerator3.h"
#include "../GameObject/TestObject/PlayerHpUi/PlayerHpUi.h"
#include "../GameObject/TestObject/GameEndChecker/GameEndChecker.h"

#include "../GameObject/TestObject/AnimSample/AnimSample.h"
#include "../GameObject/TestObject/GamePlayBgmPlayer/GamePlayBgmPlayer.h"
#include "../GameObject/ResultObject/Score/Score.h"
#include "../GameObject/MainObject/Score_Screen/Score_screen.h"



Main3Scene::Main3Scene()
{
}

// シーンの開始時に呼ばれる
void Main3Scene::start()
{
	//背景2を生成する
	BackGround_3::create(Vector2(-10,0));
	BackGround_3::create(Vector2(SCREEN_SIZE_X/2, 0));
	BackGround_3::create(Vector2(SCREEN_SIZE_X, 0));

	// プレイヤーを生成する
	Player::create(SCREEN_SIZE / 2);

	//コアを生成する
	Core::create(SCREEN_SIZE / 2);

	// プレイヤーのHPゲージを生成する
	PlayerHpUi::create(Vector2(20.0f, SCREEN_SIZE_Y - 30.0f));

	// エネミージェネレーターを生成する
	EnemyGenerator3::create();

	// ゲーム終了条件を判定するクラスを生成する
	GameEndChecker::create();

	// ゲームプレイ用のBGMプレイヤーを生成
	GamePlayBgmPlayer::create();

	// スコアを生成
	Score::create();
}

// 毎フレーム呼ばれる
void Main3Scene::update()
{
	// スコア表示部を生成
	float Complement = 30.0f; // 数字間の隙間

	float x = 0.0f;
	float Crack = 128.0f / 10.0f + Complement;
	Score_Screen_1::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_2::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_3::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_4::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_5::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_6::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_7::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_8::create(Vector2(x, 0.0f));
	x += Crack;
	Score_Screen_9::create(Vector2(x, 0.0f));

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
void Main3Scene::end()
{
	// 全てのゲームオブジェクトに「DIE_GAMEPLAY_OBJECT」のメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_GAMEPLAY_OBJECT);
}

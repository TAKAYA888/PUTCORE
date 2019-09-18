#include "MainScene.h"

#include "../GameObject/TestObject/Core/StayCore/Core.h"
#include "../GameObject/TestObject/BackGround/BackGround1/BackGround_1.h"
#include "../GameObject/PauseObject/PauseLogo/PauseLogo.h"
#include "../GameObject/PauseObject/RestartButton/RestartButton.h"
#include "../GameObject/TestObject/Player/Player.h"
#include "../GameObject/TestObject/EnemyGenerator/EnemyGenerator.h"
#include "../GameObject/TestObject/PlayerHpUi/PlayerHpUi.h"
#include "../GameObject/TestObject/GameEndChecker/GameEndChecker.h"

#include "../GameObject/TestObject/AnimSample/AnimSample.h"
#include "../GameObject/TestObject/GamePlayBgmPlayer/GamePlayBgmPlayer.h"
#include "../GameObject/ResultObject/Score/Score.h"
#include "../GameObject/MainObject/Score_screen.h"


MainScene::MainScene()
{
}

// シーンの開始時に呼ばれる
void MainScene::start()
{
	//背景１を生成する
	BackGround_1::create(SCREEN_SIZE/2);
	BackGround_1::create(Vector2(1920, 360));

	// プレイヤーを生成する
	Player::create(SCREEN_SIZE / 2);

	//コアを生成する
	Core::create(SCREEN_SIZE / 2);

	// プレイヤーのHPゲージを生成する
	PlayerHpUi::create(Vector2(10.0f, SCREEN_SIZE_Y - 20.0f));

	// エネミージェネレーターを生成する
	EnemyGenerator::create();

	// ゲーム終了条件を判定するクラスを生成する
	GameEndChecker::create();

	// アニメーションサンプルを生成
	AnimSample::create(Vector2(SCREEN_SIZE.x / 2, 32.0f));

	// ゲームプレイ用のBGMプレイヤーを生成
	GamePlayBgmPlayer::create();

	// スコアを生成
	Score::create();


	// スコア表示部を生成
	float Complement = 2.0f; // 数字間の隙間

	float x = 0.0f;
	float Crack = 128.0f / 10.0f + Complement;
	
	// 左から1（だれかここをforに変えてください笑）
	Score_Screen_1::create(Vector2(x, 0.0f));
	x += Crack;
	//Score_Screen_2::create(Vector2(x, 0.0f));
	//x += Crack;
	//Score_Screen_3::create(Vector2(x, 0.0f));
	//x += Crack;
	//Score_Screen_4::create(Vector2(x, 0.0f));
	//x += Crack;
	//Score_Screen_5::create(Vector2(x, 0.0f));
	//x += Crack;
	//Score_Screen_6::create(Vector2(x, 0.0f));
	//x += Crack;
	//Score_Screen_7::create(Vector2(x, 0.0f));
	//x += Crack;
	//Score_Screen_8::create(Vector2(x, 0.0f));
	//x += Crack;
	//Score_Screen_9::create(Vector2(x, 0.0f));
}

// 毎フレーム呼ばれる
void MainScene::update()
{
	if (Keyboard::getState(InputType::INPUT_ENDED, KeyboardKeyType::KEYBOARD_TAB))
	{
		float TimeScale = 0.0f;
		TimeScale = TktkTime::getTimeScale();
		if (TimeScale >= 0.9f) 
		{
			//GameObjectManager::findGameObjectWithTag(AKITA_BANZAI).lock()->getComponent<BackGround_1Script>().lock()->setActive(false);
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
			//BGよ！動け！
			//GameObjectManager::findGameObjectWithTag(AKITA_BANZAI).lock()->getComponent<BackGround_1Script>().lock()->setActive(true);
		}
	}
}

// シーンの終了時に呼ばれる
void MainScene::end()
{
	// 全てのゲームオブジェクトに「DIE_GAMEPLAY_OBJECT」のメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_GAMEPLAY_OBJECT);
}

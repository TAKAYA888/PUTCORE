#include "MainScene.h"

#include "../GameObject/TestObject/Player/Player.h"
#include "../GameObject/TestObject/EnemyGenerator/EnemyGenerator.h"
#include "../GameObject/TestObject/PlayerHpUi/PlayerHpUi.h"
#include "../GameObject/TestObject/GameEndChecker/GameEndChecker.h"

#include "../GameObject/TestObject/AnimSample/AnimSample.h"
#include "../GameObject/TestObject/GamePlayBgmPlayer/GamePlayBgmPlayer.h"

MainScene::MainScene()
{
}

// シーンの開始時に呼ばれる
void MainScene::start()
{
	// プレイヤーを生成する
	Player::create(SCREEN_SIZE / 2);

	// プレイヤーのHPゲージを生成する
	PlayerHpUi::create(Vector2(10.0f, 10.0f));

	// エネミージェネレーターを生成する
	EnemyGenerator::create();

	// ゲーム終了条件を判定するクラスを生成する
	GameEndChecker::create();

	// アニメーションサンプルを生成
	AnimSample::create(Vector2(SCREEN_SIZE.x / 2, 32.0f));

	// ゲームプレイ用のBGMプレイヤーを生成
	GamePlayBgmPlayer::create();
}

// 毎フレーム呼ばれる
void MainScene::update()
{
	
}

// シーンの終了時に呼ばれる
void MainScene::end()
{
	// 全てのゲームオブジェクトに「DIE_GAMEPLAY_OBJECT」のメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_GAMEPLAY_OBJECT);
}

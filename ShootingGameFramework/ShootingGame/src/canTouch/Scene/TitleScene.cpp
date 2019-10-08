#include "TitleScene.h"

#include "../GameObject/TitleObject/TitleLogo/TitleLogo.h"
#include "../GameObject/TitleObject/TitleCursor/TitleCursor.h"
#include "../GameObject/TitleObject/TitleMenuItem/GameStartItem/GameStartItem.h"
#include "../GameObject/TitleObject/TitleMenuItem/SelectMenuItem/SelectMenuItem.h"
#include "../GameObject/TitleObject/TitleMenuItem/TitleDummyItem/TitleDummyItem.h"
#include "../GameObject/TestObject/GamePlayBgmPlayer/GamePlayBgmPlayer.h"

TitleScene::TitleScene()
{
}

// シーンの開始時に呼ばれる
void TitleScene::start()
{
	// タイトルロゴを生成する
	TitleLogo::create();

	// タイトルカーソルを生成する
	TitleCursor::create();

	// タイトルメニューのゲーム開始項目を生成する
	GameStartItem::create(Vector2(SCREEN_SIZE.x / 2, 000.0f));

	//ステージセレクトボタンを生成
	SelectMenuItem::create(Vector2(SCREEN_SIZE.x / 2, 000.0f));

	// タイトル用のBGMプレイヤーを生成
	GamePlayBgmPlayer::title();
}

// 毎フレーム呼ばれる
void TitleScene::update()
{
	counter++;
}

// シーンの終了時に呼ばれる
void TitleScene::end()
{
	// 全てのゲームオブジェクトに「DIE_TITLE_OBJECT」のメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_TITLE_OBJECT);
}
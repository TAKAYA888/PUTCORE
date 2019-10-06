#include "StageSelectScene.h"
#include "../GameObject/StageSelectObject/StageSelectLogo/StageSelectLogo.h"
#include "../GameObject/TitleObject/TitleCursor/TitleCursor.h"
#include "../GameObject/TitleObject/TitleMenuItem/GameStartItem/GameStartItem.h"
#include "../GameObject/TitleObject/TitleMenuItem/SelectMenuItem/SelectMenuItem.h"
#include "../GameObject/TitleObject/TitleMenuItem/TitleDummyItem/TitleDummyItem.h"
#include "../GameObject/TestObject/GamePlayBgmPlayer/GamePlayBgmPlayer.h"

StageSelectScene::StageSelectScene()
{
}

// シーンの開始時に呼ばれる
void StageSelectScene::start()
{
	// タイトルロゴを生成する
	StageSelectLogo::create();

	

}

// 毎フレーム呼ばれる
void StageSelectScene::update()
{
	counter++;
}

// シーンの終了時に呼ばれる
void StageSelectScene::end()
{
	// 全てのゲームオブジェクトに「DIE_TITLE_OBJECT」のメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_TITLE_OBJECT);
}
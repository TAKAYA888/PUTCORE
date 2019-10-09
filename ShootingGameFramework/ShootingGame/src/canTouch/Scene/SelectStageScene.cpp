#include"SelectStageScene.h"

#include "../GameObject/StageSelectObject/StageSelectLogo/StageSelectLogo.h"
#include "../GameObject/StageSelectObject/StageSelectOneItem/StageSelectOneItem.h"
#include "../GameObject/StageSelectObject/StageSelectTwoItem/StageSelectTwoItem.h"
#include "../GameObject/StageSelectObject/StageSelectThreeItem/StageSelectThreeItem.h"
#include "../GameObject/StageSelectObject/BacktoTitileItem/BacktoTitileItem.h"





SelectStageScene::SelectStageScene()
{

}

// シーンの開始時に呼ばれる
void SelectStageScene::start()
{
	//背景～この手紙～♪よんでーいるあなたはー♪
	StageSelectLogo::create();

	//ステージ１のボタン
	StageSelectOneItem::create(Vector2(SCREEN_SIZE.x / 5, 700.0f));

	//ステージ２の牡丹
	StageSelectTwoItem::create(Vector2(SCREEN_SIZE.x / 2, 700.0f));

	//ステージ３の釦
	StageSelectThreeItem::create(Vector2(SCREEN_SIZE.x / 1,800.0f));	

	//タイトルに戻るボタン
	BacktoTitileItem::create(Vector2(SCREEN_SIZE.x / 2,500.0f));

}

// 毎フレーム呼ばれる
void SelectStageScene::update()
{
	counter++;
}

// シーンの終了時に呼ばれる
void SelectStageScene::end()
{
	// 全てのゲームオブジェクトに「DIE_TITLE_OBJECT」のメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_TITLE_OBJECT);
}
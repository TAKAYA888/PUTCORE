#include"SelectStageScene.h"

#include "../GameObject/StageSelectObject/StageSelectLogo/StageSelectLogo.h"

SelectStageScene::SelectStageScene()
{

}

// シーンの開始時に呼ばれる
void SelectStageScene::start()
{
	StageSelectLogo::create();
	

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
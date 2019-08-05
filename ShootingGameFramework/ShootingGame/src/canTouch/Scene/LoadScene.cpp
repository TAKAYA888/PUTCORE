#include "LoadScene.h"

#include "../GameObject/LoadObject/ImageLoadObject.h"
#include "../GameObject/LoadObject/BgmLoadObject.h"
#include "../GameObject/LoadObject/SeLoadObject.h"

LoadScene::LoadScene()
{
}

// シーンの開始時に呼ばれる
void LoadScene::start()
{
	// 画像の読み込みクラスを生成（引数は読み込む画像の情報を表すテキストファイル）
	ImageLoadObject::create("res/text/resourcePaths/imageResourcePaths.txt");

	// BGMの読み込みクラスを生成（引数は読み込むBGMの情報を表すテキストファイル）
	BgmLoadObject::create("res/text/resourcePaths/bgmResourcePaths.txt");

	// SEの読み込みクラスを生成（引数は読み込むSEの情報を表すテキストファイル）
	SeLoadObject::create("res/text/resourcePaths/seResourcePaths.txt");

	
}

// 毎フレーム呼ばれる
void LoadScene::update()
{
	// シーンをメインシーンに変更
	changeScene(TITLE_SCENE);
}

// シーンの終了時に呼ばれる
void LoadScene::end()
{
	// 全てのゲームオブジェクトに「DIE_GAMEPLAY_OBJECT」のメッセージを飛ばす
	GameObjectManager::sendMessage(DIE_GAMEPLAY_OBJECT);
}

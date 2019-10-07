#pragma once

// シーンの種類
enum SceneType
{
	// ロードシーン
	LOAD_SCENE = 0,

	// タイトルシーン
	TITLE_SCENE = 1,

	// メインのシーン
	MAIN_SCENE = 2,

	// クリアのシーン
	CLEAR_SCENE = 3,

	// ゲームオーバーのシーン
	GAMEOVER_SCENE = 4,

	// リザルトのシーン
	RESULT_SCENE = 5,

	//ポーズのシーン
	PAUSE_SCENE = 6,

	//ステージセレクトシーン
	STAGE_SELECT_SCENE = 7,

	//ステージ２
	STAGE_TWO_SCENE = 8,

	//ステージ３
	STAGE_THREE_SCENE = 9,
};
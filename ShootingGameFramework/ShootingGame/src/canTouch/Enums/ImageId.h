#pragma once

// 画像のID
enum ImageId
{
	// タイトルロゴの画像
	IMAGE_TITLE_LOGO = 1,

	// クリアロゴの画像
	IMAGE_CLEAR_LOGO = 2,

	// ゲームオーバーのロゴの画像
	IMAGE_GAMEOVER_LOGO = 3,

	// リザルトのロゴの画像
	IMAGE_RESULT_LOGO = 4,


	//ポーズのロゴの画像
	IMAGE_PAUSE_LOGO = 6,

	// タイトルカーソルの画像
	IMAGE_TITLE_CURSOR = 10,

	//スペースを押せという画像
	IMAGE_PUSH_SPACE = 11,

	// タイトルメニューのゲームスタートの項目の画像
	IMAGE_TITLE_MENU_GAMESTART = 20,

	//ゲームプレイ画面の背景の画像
	IMAGE_PLAY_BG = 50,

	// プレイヤーの画像
	IMAGE_PLAYER = 101,

	//コアの画像
	IMAGE_CORE = 102,

	// エネミーの画像
	IMAGE_ENEMY = 110,

	//ウイルスエネミー2の画像
	IMAGE_VIRUS_ENEMY_TWO = 112,

	// エネミーボスの画像
	IMAGE_ENEMY_BOSS = 120,

	// プレイヤーの弾の画像
	IMAGE_PLAYER_BULLET = 130,

	// 爆発の画像
	IMAGE_EXPLOSION = 140,

	// プレイヤーの体力ゲージの画像
	IMAGE_PLAYER_HP_GAUGE = 200,

	// アニメーションのテスト画像
	IMAGE_ANIM_SAMPLE = 1000,
};
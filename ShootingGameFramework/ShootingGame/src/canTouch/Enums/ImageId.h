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

	// タイトルカーソルの画像
	IMAGE_TITLE_CURSOR = 10,

	//スペースを押せという画像
	IMAGE_PUSH_SPACE = 11,

	//面倒くさがった為に出来た産物
	IMAGE_TITLE_MENU_DUMMY = 19,

	// タイトルメニューのゲームスタートの項目の画像
	IMAGE_TITLE_MENU_GAMESTART = 20,

	IMAGE_TITLE_MENU_GAMEEND = 30,

	//ゲームプレイ画面の背景の画像
	IMAGE_PLAY_BG = 50,

	// プレイヤーの画像
	IMAGE_PLAYER = 101,

	//コアの画像
	IMAGE_CORE = 102,

	// エネミーの画像
	IMAGE_ENEMY = 110,

	//ウイルスエネミー1の画像
	IMAGE_VIRUS_ENEMY_ONE = 111,

	//ウイルスエネミー2の画像
	IMAGE_VIRUS_ENEMY_TWO = 112,

	// エネミーボスの画像
	IMAGE_ENEMY_BOSS = 120,

	//ボスの画像
	IMAGE_ENEMY_BOSS_1 = 121,

	//ボスの気絶時の画像
	IMAGE_ENEMY_BOSS_FAINT = 122,

	// プレイヤーの弾の画像
	IMAGE_PLAYER_BULLET = 130,

	//ウイルスエネミーの弾の画像
	IMAGE_VIRUS_ENEMY_BULLET = 131,

	// 爆発の画像
	IMAGE_EXPLOSION = 140,

	//エネミー用の爆発の画像
	IMAGE_EXPLOSION_ENEMY = 141,

	//ボス１用の移動時のエフェクト
	IMAGE_BOSS_TELEPORTATION = 142,

	// プレイヤーの体力ゲージの画像
	IMAGE_PLAYER_HP_GAUGE = 200,

	//ポーズのロゴの画像
	IMAGE_PAUSE_LOGO = 300,

	//タイトルバック
	IMAGE_PAUSE_BACK = 302,

	// アニメーションのテスト画像
	IMAGE_ANIM_SAMPLE = 1000,

	//Boss１の死亡時のアニメーション
	IMAGE_BOSS_DEAD = 1001,

	//スコアの数字
	SCORE_NUMBER = 2000,
};
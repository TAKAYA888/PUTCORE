#pragma once

// 全体に送るメッセージの種類
enum EventMessageType
{
	// メッセージ無し
	NO_MESSAGE = 0,


	// オブジェクト関連-------------------------------------

	// ロードシーンのゲームオブジェクト全部死ね
	DIE_LOAD_OBJECT,

	// タイトルのゲームオブジェクト全部死ね
	DIE_TITLE_OBJECT,

	// ゲームプレイのゲームオブジェクト全部死ね
	DIE_GAMEPLAY_OBJECT,

	// シーン関連-------------------------------------------

	// ポーズが終わる
	PAUSE_END,

	// ゲーうオーバー、ゲームクリアが死ぬ
	DIE_O_C,

	// リザルトが死ぬ
	DIE_RESULT,


	// エネミー関連-----------------------------------------

	// エネミーボスが死んだ
	ENEMY_BOSS_DEAD,

	//エネミー1-1死亡
	DIE_Enemy1_1,

	//エネミー1-2死亡
	DIE_Enemy1_2,

	//エネミー1-3死亡
	DIE_Enemy2,

	//エネミー3-1死亡
	DIE_Enemy3_1,

	//Boss1が死んだ
	DIE_BOSS1_DEAD,
};
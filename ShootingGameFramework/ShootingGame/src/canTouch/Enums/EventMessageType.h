#pragma once

// 全体に送るメッセージの種類
enum EventMessageType
{
	// メッセージ無し
	NO_MESSAGE = 0,

	// ロードシーンのゲームオブジェクト全部死ね
	DIE_LOAD_OBJECT,

	// タイトルのゲームオブジェクト全部死ね
	DIE_TITLE_OBJECT,

	// ゲームプレイのゲームオブジェクト全部死ね
	DIE_GAMEPLAY_OBJECT,

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
};
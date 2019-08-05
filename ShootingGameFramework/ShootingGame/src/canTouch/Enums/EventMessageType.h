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
};
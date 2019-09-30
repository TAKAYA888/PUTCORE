#pragma once

// ゲームオブジェクトを識別するためのタグ
enum GameObjectTag
{
	// タグ無し
	GAME_OBJECT_TAG_NONE = 0,

	// メニューカーソル
	GAME_OBJECT_TAG_CURSOR,

	// メニュー項目
	GAME_OBJECT_TAG_MENU_ITEM,

	// プレイヤー
	GAME_OBJECT_TAG_PLAYER,

	// アイテム
	GAME_OBJECT_TAG_ITEM,

	//コア
	GAME_OBJECT_TAG_CORE,

	// 敵
	GAME_OBJECT_TAG_ENEMY,

	// ボス
	GAME_OBJECT_TAG_ENEMY_BOSS,

	// プレイヤーの弾
	GAME_OBJECT_TAG_PLAYER_BULLET,

	//コアの弾
	GAME_OBJECT_TAG_CORE_BULLET,

	// 敵の弾
	GAME_OBJECT_TAG_ENEMY_BULLET,

	//BG
	AKITA_BANZAI,
};
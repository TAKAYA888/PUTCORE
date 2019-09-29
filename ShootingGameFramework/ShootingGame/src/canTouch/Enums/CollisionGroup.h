#pragma once

// 衝突判定のグループ
enum CollisionGroup
{
	// 衝突判定無し
	COLLISION_GROUP_NONE,

	// カーソルの衝突判定
	COLLISION_GROUP_CURSOR,

	// メニュー項目の衝突判定
	COLLISION_GROUP_MENU_ITEM,

	// プレイヤーの衝突判定
	COLLISION_GROUP_PLAYER,
	COLLISION_GROUP_ITEM,
	//コアの衝突判定
	COLLISION_GROUP_CORE,

	// 敵の衝突判定
	COLLISION_GROUP_ENEMY,


	// プレイヤーの弾の衝突判定
	COLLISION_GROUP_PLAYER_BULLET,

	//コアの弾の衝突判定
	COLLISION_GROUP_CORE_BULLET,

	// 敵の弾の衝突判定
	COLLISION_GROUP_ENEMY_BULLET,
};
#pragma once

// 数字が小さい方が先に描画される
namespace DrawPriority
{
	const float DRAW_PRIORITY_BACK_GROUND = -100.0f;

	// 敵の弾を描画するレイヤー
	const float DRAW_PRIORITY_ENEMY_BULLET = 10.0f;

	// プレイヤーの弾を描画するレイヤー
	const float DRAW_PRIORITY_PLAYER_BULLET = 20.0f;

	// 敵を描画するレイヤー
	const float DRAW_PRIORITY_ENEMY = 30.0f;

	// プレイヤーを描画するレイヤー
	const float DRAW_PRIORITY_PLAYER = 40.0f;

	// 敵のボスを描画するレイヤー
	const float DRAW_PRIORITY_ENEMY_BOSS = 50.0f;

	// エフェクトを描画するレイヤー
	const float  DRAW_PRIORITY_EFFECT = 60.0f;

	// UIを描画するレイヤー
	const float DRAW_PRIORITY_UI = 100.0f;

	// デバック表示を描画するレイヤー
	const float DRAW_PRIORITY_DEBUG_FLAME = 100.0f;
}
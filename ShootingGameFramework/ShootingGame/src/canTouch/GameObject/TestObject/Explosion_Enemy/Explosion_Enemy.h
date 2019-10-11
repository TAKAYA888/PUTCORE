#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "Explosion_EnemyScript.h"

struct Explosion_Enemy
{
	static void create(const Vector2& position)
	{
		// ゲームオブジェクトを作成
		auto explosion_enemy = std::make_shared<GameObject>();

		// ２次元座標
		explosion_enemy->addComponent(std::make_shared<Transform2D>(
			position,				// 座標（引数から受け取る）
			Vector2(1.0f, 1.0f),	// スケール（倍率）
			0.0f					// 回転（度数法）
			));

		// ２次元画像の描画
		explosion_enemy->addComponent(std::make_shared<Sprite2dDrawer>(
			DrawPriority::DRAW_PRIORITY_EFFECT,			// 描画するレイヤー
			IMAGE_EXPLOSION_ENEMY,		// 描画する画像のID
			0,						// 左上から見て何番目の位置の画像を表示するか
			Vector2(0.5f, 0.5f)		// 画像の中心（割合）
			));

		// ２次元画像をアニメーションさせるコンポーネント
		explosion_enemy->addComponent(std::make_shared<AnimatedSprite2d>(
			IMAGE_EXPLOSION_ENEMY,	// アニメーションで使用する画像の種類
			0,					// 最小の左上基準の画像番号
			16,					// 最大の左上基準の画像番号
			0.1f,				// 何秒間で次の画像に変わるか
			false				// アニメーションをループさせるか？
			));

		// サウンドを再生するコンポーネント
		explosion_enemy->addComponent(std::make_shared<SePlayer>(
			enemy_damage 	// サウンドの名前
			));

		// 爆発のスクリプトを生成する
		explosion_enemy->addComponent(std::make_shared<Explosion_EnemyScript>());

		// ゲームオブジェクトを追加
		GameObjectManager::addGameObject(explosion_enemy);
	}
};
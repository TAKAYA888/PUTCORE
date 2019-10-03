#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

class Boss3Script
	:public ComponentBase
{
public:

	Boss3Script();

public:

	// 毎フレーム呼ばれる
	void update();

	// 衝突開始で呼ばれる
	void onCollisionEnter(GameObjectPtr other);

	// 衝突中で呼ばれる
	void onCollisionStay(GameObjectPtr other);

	// 衝突終了で呼ばれる
	void onCollisionExit(GameObjectPtr other);

	// メッセージ受信時に呼ばれる
	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

	// 消える直前に呼ばれる
	void onDestroy();

private:

	//射撃1
	void Shot1();

	//射撃2
	void Shot2();

	//移動
	void Move();

private:

	// 体力
	int m_hp{ 800 };

	//タイマー
	float timer;

	// 弾を発射する間隔
	const float m_shotInterval{ 2.0f };

	// 弾を発射するタイマー
	float m_shotTimer{ 0.0f };

	//カウンター
	int counter;

	//プレイヤーのポジションを保存する
	Vector2 playerPos;

	//プレイヤーが死んだかどうか
	bool PlayerFrag;

	//射撃したかどうか
	bool ShotFrag[6] = { true,true,true,true,true,true };

	//射撃したかどうか
	bool ShotFrag2;

	//エネミーを出したかどうか
	bool EnemyFrag[3] = { true,true,true };

	bool EnemyFrag2[3] = { true,true,true };

	bool EnemyFrag3[3] = { true,true,true };

	bool EnemyFrag4[3] = { true,true,true };

	//行動パターンの変更
	int ActionCounter{ 0 };

	//射撃の角度の配列
	int shotAngle1[5] = { 0,15,30,345,330 };

	int shotAngle2[4] = { 10,20,350,340 };

};
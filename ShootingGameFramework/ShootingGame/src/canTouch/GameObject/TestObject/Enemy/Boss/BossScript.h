#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

class BossScript
	:public ComponentBase
{
public:

	enum State
	{
		normal,
		angry,
		faint,//気絶
		dying,
	};

public:

	BossScript();

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

public:

	void changeState(State nextState);

private:

	// 移動
	void move();

	//射撃
	void Shot();

private:

	// 体力
	int m_hp{ 100 };

	float timer;

	// 弾を発射する間隔
	const float m_shotInterval{ 2.0f };

	// 弾を発射するタイマー
	float m_shotTimer{ 0.0f };

	State m_curState = State::normal;

	int counter;

	bool teleportionCounter;
};
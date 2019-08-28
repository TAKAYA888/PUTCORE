#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

class GameStartItemScript
	: public ComponentBase
{
public:

	GameStartItemScript(float moveSpeed);

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



	//追加
	void Move();

	// 移動速度
	float m_moveSpeed;

	int counter = 0;

	int select = 0;

	int Stealth = 0;

private:

	float m_curAlpha = 0.0f;
	const float m_increaseAlphaPerSec = 1.0f;

};
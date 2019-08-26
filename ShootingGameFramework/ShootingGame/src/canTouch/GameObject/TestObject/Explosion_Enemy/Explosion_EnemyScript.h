#pragma once

#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

class Explosion_EnemyScript
	: public ComponentBase
{
public:

	Explosion_EnemyScript();

public:

	void start();

	// 毎フレーム呼ばれる
	void update();

	// メッセージ受信時に呼ばれる
	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

private:

	float m_explosionTimer{ 0.0f };

	float m_deleteTimeSec{ 1.0f };
};
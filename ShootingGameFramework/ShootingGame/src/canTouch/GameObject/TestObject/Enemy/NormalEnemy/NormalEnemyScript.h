#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

class NormalEnemyScript
	: public ComponentBase
{
public:

	NormalEnemyScript();

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

private:

	// 移動
	void move();

	// 弾を発射
	void shot();

private:

	// 体力
	int m_hp{ 5 };

	// 弾を発射する間隔
	const float m_shotInterval{ 1.0f };

	// 弾を発射するタイマー
	float m_shotTimer{ 0.0f };
};
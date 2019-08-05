#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

class PlayerScript
	: public ComponentBase
{
public:

	PlayerScript(
		float moveSpeed
	);

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

public:

	// 最大の体力を取得
	int getMaxHp() const;

	// 現在の体力を取得
	int getCurHp() const;

private:

	// 入力による移動
	void inputToMove();

	// 入力による回転
	void inputToRotate();

	// 入力による発射
	void inputToShot();

private:

	// 最大の体力
	int m_maxHp{ 10 };

	// 現在の体力
	int m_curHp{ 10 };

	// 移動速度
	float m_moveSpeed;
};
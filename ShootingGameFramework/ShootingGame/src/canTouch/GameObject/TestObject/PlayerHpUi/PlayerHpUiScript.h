#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

class PlayerHpUiScript
	: public ComponentBase
{
public:

	PlayerHpUiScript(float hpGaugeWidth);

public:

	// 毎フレーム呼ばれる
	void update();

	// メッセージ受信時に呼ばれる
	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

private:

	// 最大HPと現在のHPの比率を計算する
	float calculateHpRate();

private:

	// HPゲージの横幅
	float m_hpGaugeWidth;

	// プレイヤーのゲームオブジェクトのポインタ
	GameObjectPtr m_player;
};
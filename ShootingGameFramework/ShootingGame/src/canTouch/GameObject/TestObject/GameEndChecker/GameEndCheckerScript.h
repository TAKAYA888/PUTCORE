#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

class GameEndCheckerScript
	: public ComponentBase
{
public:

	GameEndCheckerScript();

public:

	// 毎フレーム呼ばれる
	void update();

	// メッセージ受信時に呼ばれる
	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

	// 消える直前に呼ばれる
	void onDestroy();

private:

	// ゲーム開始検知フラグ
	bool m_gameStart{ false };

	// ゲーム終了フラグ
	bool m_gameEnd{ false };

	// ボスを倒した数
	int m_bossKillCount{ 0 };

	// 何体のボスを倒したらクリアか？
	const int m_bossKillTargetValue{ 1 };

	// シーンが変更するまでのタイマー
	float m_sceneChangeTimer{ 0.5f };
};
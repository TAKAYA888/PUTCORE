#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

class ScoreScript
	: public ComponentBase
{
public:

	ScoreScript();

public:

	// 毎フレーム呼ばれる
	void update();

	// メッセージ受信時に呼ばれる
	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

	//Scoreのカウント
	static int score;

	////Scoreの掃き出し
	static int Score_Screen_Number(int Number);
	static int Score_arrey[10];
	static int Score_tmp;
};
#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

class Score_Screen_Script
	: public ComponentBase
{
public:

	Score_Screen_Script();

public:

	// 毎フレーム呼ばれる
	void update();

	int count;
};
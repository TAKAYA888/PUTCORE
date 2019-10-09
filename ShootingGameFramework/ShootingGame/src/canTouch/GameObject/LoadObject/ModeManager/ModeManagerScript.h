#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

class ModeManagerScript
	: public ComponentBase
{
public:

	ModeManagerScript();

public:

	// 毎フレーム呼ばれる
	void update();

};
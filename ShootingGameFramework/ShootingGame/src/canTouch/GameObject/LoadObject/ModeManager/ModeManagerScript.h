#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

#include "../../canTouch/Enums/Mode.h"

class ModeManagerScript
	: public ComponentBase
{
public:

	ModeManagerScript();

public:

	// 毎フレーム呼ばれる
	void update();

public:
	
	//現在のモードを取得
	auto getMode() const;

	//現在のモードを変更
	auto changeMode(ModeManagerScript changeMode);

};
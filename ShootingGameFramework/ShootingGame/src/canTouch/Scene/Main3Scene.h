#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

class Main3Scene
	: public SceneBase
{
public:

	Main3Scene();

	// シーンの開始時に呼ばれる
	void start() override;

	// 毎フレーム呼ばれる
	void update() override;

	// シーンの終了時に呼ばれる
	void end() override;

	int counter = 0;

};

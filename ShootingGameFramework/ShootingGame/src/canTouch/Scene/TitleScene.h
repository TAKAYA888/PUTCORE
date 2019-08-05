#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12を押してジャンプ-> */TktkManual;
/*F12を押してジャンプ-> */ProjectIncludePaths;
#endif

class TitleScene
	: public SceneBase
{
public:

	TitleScene();

	// シーンの開始時に呼ばれる
	void start() override;

	// 毎フレーム呼ばれる
	void update() override;

	// シーンの終了時に呼ばれる
	void end() override;
};
#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

class Score_Screen_Script
	: public ComponentBase
{
public:

	Score_Screen_Script();

public:

	// ���t���[���Ă΂��
	void update();

	int count;
};
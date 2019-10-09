#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

#include "../../canTouch/Enums/Mode.h"

class ModeManagerScript
	: public ComponentBase
{
public:

	ModeManagerScript();

public:

	// ���t���[���Ă΂��
	void update();

public:
	
	//���݂̃��[�h���擾
	auto getMode() const;

	//���݂̃��[�h��ύX
	auto changeMode(ModeManagerScript changeMode);

};
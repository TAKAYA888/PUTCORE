#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

class ScoreScript
	: public ComponentBase
{
public:

	ScoreScript();

public:

	// ���t���[���Ă΂��
	void update();

	// ���b�Z�[�W��M���ɌĂ΂��
	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

	//Score�̃J�E���g
	static int score;

	////Score�̑|���o��
	static int Score_Screen_Number(int Number);
	static int Score_arrey[10];
	static int Score_tmp;
};
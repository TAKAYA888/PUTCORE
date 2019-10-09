#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

class StageSelectLogoScript
	: public ComponentBase
{
public:

	StageSelectLogoScript();

public:

	// ���t���[���Ă΂��
	void update();

	// ���b�Z�[�W��M���ɌĂ΂��
	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

private:

	float m_curAlpha = 0.0f;
	const float m_increaseAlphaPerSec = 2.5f;
};
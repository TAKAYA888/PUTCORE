#pragma once

#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

class ExplosionScript
	: public ComponentBase
{
public:

	ExplosionScript();

public:

	void start();

	// ���t���[���Ă΂��
	void update();

private:

	float m_explosionTimer{ 0.0f };

	float m_deleteTimeSec{ 1.0f };
};
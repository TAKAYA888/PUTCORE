#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

class TitleScene
	: public SceneBase
{
public:

	TitleScene();

	// �V�[���̊J�n���ɌĂ΂��
	void start() override;

	// ���t���[���Ă΂��
	void update() override;

	// �V�[���̏I�����ɌĂ΂��
	void end() override;
};
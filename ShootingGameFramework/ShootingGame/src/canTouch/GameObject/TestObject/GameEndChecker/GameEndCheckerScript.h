#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

class GameEndCheckerScript
	: public ComponentBase
{
public:

	GameEndCheckerScript();

public:

	// ���t���[���Ă΂��
	void update();

	// ���b�Z�[�W��M���ɌĂ΂��
	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

	// �����钼�O�ɌĂ΂��
	void onDestroy();

private:

	// �Q�[���J�n���m�t���O
	bool m_gameStart{ false };

	// �Q�[���I���t���O
	bool m_gameEnd{ false };

	// �{�X��|������
	int m_bossKillCount{ 0 };

	// ���̂̃{�X��|������N���A���H
	const int m_bossKillTargetValue{ 1 };

	// �V�[�����ύX����܂ł̃^�C�}�[
	float m_sceneChangeTimer{ 0.5f };
};
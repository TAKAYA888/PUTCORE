#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

class PlayerHpUiScript
	: public ComponentBase
{
public:

	PlayerHpUiScript(float hpGaugeWidth);

public:

	// ���t���[���Ă΂��
	void update();

	// ���b�Z�[�W��M���ɌĂ΂��
	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

private:

	// �ő�HP�ƌ��݂�HP�̔䗦���v�Z����
	float calculateHpRate();

private:

	// HP�Q�[�W�̉���
	float m_hpGaugeWidth;

	// �v���C���[�̃Q�[���I�u�W�F�N�g�̃|�C���^
	GameObjectPtr m_player;
};
#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

class Boss2Script
	:public ComponentBase
{
public:

	Boss2Script();

public:

	// ���t���[���Ă΂��
	void update();

	// �ՓˊJ�n�ŌĂ΂��
	void onCollisionEnter(GameObjectPtr other);

	// �Փ˒��ŌĂ΂��
	void onCollisionStay(GameObjectPtr other);

	// �ՓˏI���ŌĂ΂��
	void onCollisionExit(GameObjectPtr other);

	// ���b�Z�[�W��M���ɌĂ΂��
	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

	// �����钼�O�ɌĂ΂��
	void onDestroy();

private:

	//�ˌ�
	void Shot();

private:

	// �̗�
	int m_hp{ 500 };

	float timer;

	// �e�𔭎˂���Ԋu
	const float m_shotInterval{ 2.0f };

	// �e�𔭎˂���^�C�}�[
	float m_shotTimer{ 0.0f };

	int counter;

};
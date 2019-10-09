#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

class zako6UpScript
	:public ComponentBase
{
public:

	zako6UpScript();

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

	// �ړ�
	void move();

	//�p���[�A�b�v�A�C�e���o��
	void PowerupItem();

	//�񕜃A�C�e���o��
	void RecoveryItem();

private:

	// �̗�
	int m_hp{ 3 };

	float timer;

	int add_core_bullet;

	int counter;

	bool playerFrag;

	/*auto Velocity;*/
};
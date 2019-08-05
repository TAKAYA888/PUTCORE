#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

class NormalEnemyScript
	: public ComponentBase
{
public:

	NormalEnemyScript();

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

private:

	// �ړ�
	void move();

	// �e�𔭎�
	void shot();

private:

	// �̗�
	int m_hp{ 5 };

	// �e�𔭎˂���Ԋu
	const float m_shotInterval{ 1.0f };

	// �e�𔭎˂���^�C�}�[
	float m_shotTimer{ 0.0f };
};
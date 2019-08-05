#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

class PlayerScript
	: public ComponentBase
{
public:

	PlayerScript(
		float moveSpeed
	);

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

public:

	// �ő�̗̑͂��擾
	int getMaxHp() const;

	// ���݂̗̑͂��擾
	int getCurHp() const;

private:

	// ���͂ɂ��ړ�
	void inputToMove();

	// ���͂ɂ���]
	void inputToRotate();

	// ���͂ɂ�锭��
	void inputToShot();

private:

	// �ő�̗̑�
	int m_maxHp{ 10 };

	// ���݂̗̑�
	int m_curHp{ 10 };

	// �ړ����x
	float m_moveSpeed;
};
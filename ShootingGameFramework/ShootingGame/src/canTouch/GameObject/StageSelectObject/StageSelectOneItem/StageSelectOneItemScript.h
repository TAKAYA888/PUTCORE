#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

class StageSelectOneItemScript
	: public ComponentBase
{
public:

	StageSelectOneItemScript(float moveSpeed);

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

	//�ǉ�
	void Move();

	// �ړ����x
	float m_moveSpeed;

	int counter = 0;

	int select = 0;

	int Stealth = 0;

private:

	bool stickfrag = true;
	float timer = 0;
	bool frag = true;
	float m_curAlpha = 0.0f;
	const float m_increaseAlphaPerSec = 1.0f;
	Vector2 moveVelocity = Vector2::zero;
};

#pragma once

#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

class Boss3Script
	:public ComponentBase
{
public:

	Boss3Script();

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

	//�ˌ�1
	void Shot1();

	//�ˌ�2
	void Shot2();

	//�ړ�
	void Move();

private:

	// �̗�
	int m_hp{ 800 };

	//�^�C�}�[
	float timer;

	// �e�𔭎˂���Ԋu
	const float m_shotInterval{ 2.0f };

	// �e�𔭎˂���^�C�}�[
	float m_shotTimer{ 0.0f };

	//�J�E���^�[
	int counter;

	//�v���C���[�̃|�W�V������ۑ�����
	Vector2 playerPos;

	//�v���C���[�����񂾂��ǂ���
	bool PlayerFrag;

	//�ˌ��������ǂ���
	bool ShotFrag[6] = { true,true,true,true,true,true };

	//�ˌ��������ǂ���
	bool ShotFrag2;

	//�G�l�~�[���o�������ǂ���
	bool EnemyFrag[3] = { true,true,true };

	bool EnemyFrag2[3] = { true,true,true };

	bool EnemyFrag3[3] = { true,true,true };

	bool EnemyFrag4[3] = { true,true,true };

	//�s���p�^�[���̕ύX
	int ActionCounter{ 0 };

	//�ˌ��̊p�x�̔z��
	int shotAngle1[5] = { 0,15,30,345,330 };

	int shotAngle2[4] = { 10,20,350,340 };

};
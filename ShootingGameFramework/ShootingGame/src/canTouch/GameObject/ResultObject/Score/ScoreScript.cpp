#include "ScoreScript.h"

ScoreScript::ScoreScript()
{
	//score��0����
	score = 0;
}

void ScoreScript::update()
{
}

void ScoreScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	//�^�C�g�������ʂƃX�R�A�����Z�b�g����܂�
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		score = 0;
	}

	//��ŕύX���₷���悤�ɃG�l�~�[���Ƃɕ����Ă���܂�
	//�d�g�݂̓G�l�~�[�����ʂ�eventMessage�𗬂��̂ł�����󂯎��Score�Ƀv���X���Ă��܂�

	if (eventMessageType == DIE_Enemy1_1)
	{
		score += 100;
	}

	if (eventMessageType == DIE_Enemy1_2)
	{
		score += 100;
	}

	if (eventMessageType == DIE_Enemy2)
	{
		score += 100;
	}

	if (eventMessageType == DIE_Enemy3_1)
	{
		score += 100;
	}

	if (eventMessageType == ENEMY_BOSS_DEAD)
	{
		score += 100;
	}
}

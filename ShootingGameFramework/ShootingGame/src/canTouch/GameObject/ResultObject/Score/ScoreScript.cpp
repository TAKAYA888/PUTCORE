#include "ScoreScript.h"

ScoreScript::ScoreScript()
{
	//score��0����
	score = 0;
}

void ScoreScript::update()
{
}

int ScoreScript::score;

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
		score += 1000;
	}

	if (eventMessageType == DIE_Enemy2)
	{
		score += 10000;
	}

	if (eventMessageType == DIE_Enemy3_1)
	{
		score += 100;
	}

	if (eventMessageType == DIE_BOSS1_DEAD)
	{
		score += 2000;
	}

	if (eventMessageType == DIE_BOSS2_DEAD)
	{
		score += 2000;
	}
}

int ScoreScript::Score_arrey[10];
int ScoreScript::Score_tmp;

//�X�R�A�̈ꌅ��Ԃ��܂��i����Number�ɂق������̈ʂ�����܂��@������1�ł��j
int ScoreScript::Score_Screen_Number(int Number)
{
	Score_tmp = 0;
	Score_tmp = score;
	Score_arrey[1] = Score_tmp / 100000000;
	Score_tmp %= 100000000;
	Score_arrey[2] = Score_tmp / 10000000;
	Score_tmp %= 10000000;
	Score_arrey[3] = Score_tmp / 1000000;
	Score_tmp %= 1000000;
	Score_arrey[4] = Score_tmp / 100000;
	Score_tmp %= 100000;
	Score_arrey[5] = Score_tmp / 10000;
	Score_tmp %= 10000;
	Score_arrey[6] = Score_tmp / 1000;
	Score_tmp %= 1000;
	Score_arrey[7] = Score_tmp / 100;
	Score_tmp %= 100;
	Score_arrey[8] = Score_tmp / 10;
	Score_tmp %= 10;
	Score_arrey[9] = Score_tmp / 1;

	return Score_arrey[Number];
}

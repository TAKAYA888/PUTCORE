#include "ScoreScript.h"

ScoreScript::ScoreScript()
{
	//scoreの0入れ
	score = 0;
}

void ScoreScript::update()
{
}

void ScoreScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	//タイトルが死ぬとスコアがリセットされます
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		score = 0;
	}

	//後で変更しやすいようにエネミーごとに分けてあります
	//仕組みはエネミーが死ぬとeventMessageを流すのでをれを受け取りScoreにプラスしています

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

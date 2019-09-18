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
		score += 2000;
	}
}

////スコアの一桁を返します（引数Numberにほしい桁の位をいれます　左から1です）
//int ScoreScript::Score_Screen_Number(int Number)
//{
//	if (Number == 1)Score_Number = 100000000;
//	if (Number == 2)Score_Number = 10000000;
//	if (Number == 3)Score_Number = 1000000;
//	if (Number == 4)Score_Number = 100000;
//	if (Number == 5)Score_Number = 10000;
//	if (Number == 6)Score_Number = 1000;
//	if (Number == 7)Score_Number = 100;
//	if (Number == 8)Score_Number = 10;
//	if (Number == 9)Score_Number = 1;
//
//	Score_Number = score / Score_Number;
//
//	return Score_Number;
//}

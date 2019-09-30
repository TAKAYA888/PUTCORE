#include "Score_Screen_Script.h"

Score_Screen_Script::Score_Screen_Script()
{
	count = 0;
}

void Score_Screen_Script::update()
{
	count++;
	if (count >= 2) 
	{
		getGameObject().lock()->destroy();
	}
}
#include "TitleDummyItemScript.h"




// ���t���[���Ă΂��
void TitleDummyItemScript::update()
{


}


// �ՓˊJ�n�ŌĂ΂��
void TitleDummyItemScript::onCollisionEnter(GameObjectPtr other)
{
}

// �Փ˒��ŌĂ΂��
void TitleDummyItemScript::onCollisionStay(GameObjectPtr other)
{



}

// �ՓˏI���ŌĂ΂��
void TitleDummyItemScript::onCollisionExit(GameObjectPtr other)
{
}

void TitleDummyItemScript::handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	if (eventMessageType == DIE_TITLE_OBJECT)
	{
		getGameObject().lock()->destroy();
	}
}

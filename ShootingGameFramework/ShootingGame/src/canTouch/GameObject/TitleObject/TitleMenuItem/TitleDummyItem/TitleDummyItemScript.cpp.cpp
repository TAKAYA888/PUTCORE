#include "TitleDummyItemScript.h"




// 毎フレーム呼ばれる
void TitleDummyItemScript::update()
{


}


// 衝突開始で呼ばれる
void TitleDummyItemScript::onCollisionEnter(GameObjectPtr other)
{
}

// 衝突中で呼ばれる
void TitleDummyItemScript::onCollisionStay(GameObjectPtr other)
{



}

// 衝突終了で呼ばれる
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

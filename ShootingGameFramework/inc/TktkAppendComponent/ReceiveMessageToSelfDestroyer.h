#pragma once

#include <TktkComponentFramework/Component/ComponentBase.h>

// 特定のメッセージを取得したら自身のGameObjectを削除する
class ReceiveMessageToSelfDestroyer
	: public ComponentBase
{
public:

	ReceiveMessageToSelfDestroyer(int destroyMessegeType);

	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

private:

	int m_destroyMessegeType;
};
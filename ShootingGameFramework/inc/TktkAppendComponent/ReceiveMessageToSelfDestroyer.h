#pragma once

#include <TktkComponentFramework/Component/ComponentBase.h>

// ����̃��b�Z�[�W���擾�����玩�g��GameObject���폜����
class ReceiveMessageToSelfDestroyer
	: public ComponentBase
{
public:

	ReceiveMessageToSelfDestroyer(int destroyMessegeType);

	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

private:

	int m_destroyMessegeType;
};
#pragma once

#include <TktkComponentFramework/Component/ComponentBase.h>

// �T�E���h�Đ��R���|�[�l���g
class SePlayer
	: public ComponentBase
{
public:

	SePlayer(
		int seId
	);

public:

	void playSe();

private:

	int m_seId;
};
#pragma once

#include <TktkComponentFramework/Component/ComponentBase.h>

// サウンド再生コンポーネント
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
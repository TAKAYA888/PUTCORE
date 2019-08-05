#pragma once

#include <TktkComponentFramework/Component/ComponentBase.h>

// BGM再生コンポーネント
class BgmPlayer
	: public ComponentBase
{
public:

	BgmPlayer(
		int bgmId,
		bool startToPlay
	);

	void start();

	void onDestroy();

public:

	void playBgm();

	void stopBgm();

	void changeBgm(int bgmId);

private:

	int m_bgmId;

	bool m_startToPlay;
};
#pragma once

#include <ctime>

// 時間管理クラス
class TktkTime
{
public:

	static void initalize(
		int baseFps = 60	// 基準となるFPS
	);

	static void update();

	static float deltaTime();

	// プログラムが起動してからの時間（秒）を返す
	static float getCurTimeSec();

	// 時間の経過速度割合を取得する
	static float getTimeScale();

	// 時間の経過速度割合を設定する（0.0～1.0）
	static void setTimeScale(float timeScaleRate);

	// 基準となるFPSを取得する
	static int baseFps();					

	// 瞬間的なFPSを取得する
	static float fps();

private:

	static int m_baseFps;

	static std::clock_t m_startTime;

	static std::clock_t m_preTime;

	static float m_totalTime;

	static float m_deltaTime;

	static float m_maximumDeltaTime;

	static float m_timeScaleRate;
};
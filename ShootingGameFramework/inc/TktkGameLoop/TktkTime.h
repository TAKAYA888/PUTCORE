#pragma once

#include <ctime>

// ���ԊǗ��N���X
class TktkTime
{
public:

	static void initalize(
		int baseFps = 60	// ��ƂȂ�FPS
	);

	static void update();

	static float deltaTime();

	// �v���O�������N�����Ă���̎��ԁi�b�j��Ԃ�
	static float getCurTimeSec();

	// ���Ԃ̌o�ߑ��x�������擾����
	static float getTimeScale();

	// ���Ԃ̌o�ߑ��x������ݒ肷��i0.0�`1.0�j
	static void setTimeScale(float timeScaleRate);

	// ��ƂȂ�FPS���擾����
	static int baseFps();					

	// �u�ԓI��FPS���擾����
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
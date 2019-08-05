#ifndef GAME_PAD_H_
#define GAME_PAD_H_

#include <DxLib.h>
#include <vector>
#include <map>
#include <TktkMath/Vector2.h>

#include "../InputType.h"
#include "GamePadNumber.h"
#include "GamePadButtonType.h"

// �Q�[���p�b�h���͎�t�N���X
class GamePad
{
public:

	static void initialize();

	// ���̃R���g���[���[���g�p���邩�H�i�����l�͂P�j
	static void setGamePadCount(int gamePadCount);

	static void update();

	// �E������GamePadNumber�̗񋓌^�i��r�b�g�t���O�j��
	//   InputType��GamePadButtonType�̗񋓌^�i�r�b�g�t���O�j
	static bool getState(GamePadNumber padNumber, int inputType, int gamePadButtonType);

	static Vector2 getLeftStick(GamePadNumber padNumber, bool getPreviosState = false);

	static Vector2 getRightStick(GamePadNumber padNumber, bool getPreviosState = false);

	static float getLeftTrigger(GamePadNumber padNumber, bool getPreviosState = false);

	static float getRightTrigger(GamePadNumber padNumber, bool getPreviosState = false);

	static void finalize();

private:

	static bool checkBitFlag(XINPUT_STATE inputState, int gamePadButtonType);

private:

	static int m_gamePadCount;

	static std::vector<XINPUT_STATE> m_currentState;

	static std::vector<XINPUT_STATE> m_previosState;

	static std::map<int, int> m_xInputBitFlagMap;
};
#endif // !GAME_PAD_H_
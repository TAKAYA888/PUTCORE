#ifndef LATE_PAD_INPUT_H_
#define LATE_PAD_INPUT_H_

#include <map>
#include <vector>
#include <TktkMath/Vector2.h>

#include "GamePad.h"
#include "GamePadButtonType.h"


class LatePadInput
{
public:
	static void initialize(unsigned int vectorSize = 30);

	static void update();

	static bool getState(GamePadNumber padNumber, int inputType, GamePadButtonType gamePadButtonType);

	static Vector2 getLeftStick(GamePadNumber padNumber, bool getPreviosState = false);

	static Vector2 getRightStick(GamePadNumber padNumber, bool getPreviosState = false);

	static float getLeftTrigger(GamePadNumber padNumber, bool getPreviosState = false);

	static float getRightTrigger(GamePadNumber padNumber, bool getPreviosState = false);

	static void finalize();

private:

	static unsigned int m_maxVectorSize;

	static std::map<GamePadButtonType, std::vector<bool>> m_padStateMap;
	
	static std::vector<Vector2> m_leftStickVector;
	static std::vector<Vector2> m_rightStickVector;
	static std::vector<float> m_leftTriggerVector;
	static std::vector<float> m_rightTriggerVector;
};

#endif // !LATE_PAD_INPUT_H_
#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <map>

#include "../InputType.h"
#include "KeyboardKeyType.h"

// キーボード入力受付クラス
class Keyboard
{
public:

	static void initalize();

	static void update();

	// ・引数はInputType（ビットフラグ）と
	//   KeyboardKeyTypeの列挙型（非ビットフラグ）
	static bool getState(int inputType, KeyboardKeyType keyboardKeyType);

	static void finalize();

private:

	static char m_currentKeycode[256];

	static char m_previosKeycode[256];
};

#endif // !KEYBOARD_H_

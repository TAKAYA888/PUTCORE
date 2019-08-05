#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <map>

#include "../InputType.h"
#include "KeyboardKeyType.h"

// �L�[�{�[�h���͎�t�N���X
class Keyboard
{
public:

	static void initalize();

	static void update();

	// �E������InputType�i�r�b�g�t���O�j��
	//   KeyboardKeyType�̗񋓌^�i��r�b�g�t���O�j
	static bool getState(int inputType, KeyboardKeyType keyboardKeyType);

	static void finalize();

private:

	static char m_currentKeycode[256];

	static char m_previosKeycode[256];
};

#endif // !KEYBOARD_H_

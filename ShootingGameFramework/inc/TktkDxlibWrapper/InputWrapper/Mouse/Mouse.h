#ifndef MOUSE_H_
#define MOUSE_H_

#include <TktkMath/Vector2.h>

#include "../InputType.h"
#include "MouseButtonType.h"

// �}�E�X���͎�t�N���X
class Mouse
{
public:

	static void initialize();

	static void update();

	static Vector2 getCursorPoint();

	// �E�J�[�\���̈ʒu���w����W�Ɉړ�������
	static void setCursorPoint(const Vector2& point);

	static void showCursor();

	// �E�Q�[���E�B���h�E�̒��Ɍ����ă}�E�X�J�[�\�����\���ɂ���
	static void hideCursor();

	// �E������InputType��MouseButtonType�̗񋓌^�i�r�b�g�t���O�j
	static bool getState(int inputType, int mouseButtonType);

	// �E�c�����̃}�E�X�z�C�[���̕ω��ʂ��擾�iint�j
	static int getVerticalMouseWheel();

	// �E�c�����̃}�E�X�z�C�[���̕ω��ʂ��擾�ifloat�j
	static float getVerticalMouseWheelF();

	// �E�������̃}�E�X�z�C�[���̕ω��ʂ��擾�iint�j
	static int getHorizontalMouseWheel();

	// �E�������̃}�E�X�z�C�[���̕ω��ʂ��擾�ifloat�j
	static float getHorizontalMouseWheelF();

	static void finalize();

private:

	static int m_currentState;

	static int m_previosState;
};

#endif // !MOUSE_H_
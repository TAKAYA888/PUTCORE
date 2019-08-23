#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>
#include <TktkMath/Matrix3.h>
#include <TktkMath/Vector2.h>

// �摜�Ƃ��̃A�j���[�V�������Ǘ�����N���X
class Sprite
{
public:

	// ���]�r�b�g�t���O
	enum ReverseFlag
	{
		// ���������̔��]�i�����Ȑ������ɂ��Ĕ��]�j
		HORIZONTAL_REVERSE	= 1 << 0,

		// ���������̔��]�i�����Ȑ������ɂ��Ĕ��]�j
		VERTICAL_REVERSE	= 1 << 1,

		// ���]����
		NOT_REVERSE = 0,
	};

	static void initialize();

	// �E�������Ă��Ȃ��摜�̕`��
	static void drawSprite(int id, const Matrix3& pose, const Vector2& center = Vector2(0.5f, 0.5f), unsigned int reverseFlag = NOT_REVERSE);

	// �E�������Ă��Ȃ��摜��(x, y)����(w, h)�����؂������摜�̕`��
	static void drawSprite(int id, int x, int y, int w, int h, const Matrix3& pose, const Vector2& center = Vector2(0.5f, 0.5f), unsigned int reverseFlag = NOT_REVERSE);

	// �E���������摜�̕`��
	static void drawSprite(int id, int splitGraphIndex, const Matrix3& pose, const Vector2& center = Vector2(0.5f, 0.5f), unsigned int reverseFlag = NOT_REVERSE);

	// �E���������摜��(x, y)����(w, h)�����؂������摜�̕`��
	static void drawSprite(int id, int splitGraphIndex, int x, int y, int w, int h, const Matrix3& pose, const Vector2& center = Vector2(0.5f, 0.5f), unsigned int reverseFlag = NOT_REVERSE);

	// �E������ID�Ƀe�N�X�`���f�[�^���֘A�t�����Ă��Ȃ��ꍇ�A�������s��Ȃ�
	static void erase(int id);

	// �E�����̉摜�̑傫�����擾
	static Vector2 getSpriteSize(int id);

	static Vector2 getSpriteSize(int id, int splitGraphIndex);

	static void finalize();
};

#endif // !SPRITE_H_
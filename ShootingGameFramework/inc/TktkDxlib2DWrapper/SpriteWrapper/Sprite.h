#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>
#include <TktkMath/Vector2.h>

// �摜�Ƃ��̃A�j���[�V�������Ǘ�����N���X
class Sprite
{
public:

	static void initialize();

	// �E�������Ă��Ȃ��摜�̕`��
	static void drawSprite(int id, const Vector2& position, const Vector2& center = Vector2::zero, const Vector2& scale = Vector2::one, float rotationDeg = 0.0f);

	// �E�������Ă��Ȃ��摜��(x, y)����(w, h)�����؂������摜�̕`��
	static void drawSprite(int id, const Vector2& position, int x, int y, int w, int h, const Vector2& center = Vector2::zero, const Vector2& scale = Vector2::one, float rotationDeg = 0.0f);

	// �E���������摜�̕`��
	static void drawSprite(int id, int splitGraphIndex, const Vector2& position, const Vector2& center = Vector2::zero, const Vector2& scale = Vector2::one, float rotationDeg = 0.0f);

	// �E���������摜��(x, y)����(w, h)�����؂������摜�̕`��
	static void drawSprite(int id, int splitGraphIndex, const Vector2& position, int x, int y, int w, int h, const Vector2& center = Vector2::zero, const Vector2& scale = Vector2::one, float rotationDeg = 0.0f);

	// �E������ID�Ƀe�N�X�`���f�[�^���֘A�t�����Ă��Ȃ��ꍇ�A�������s��Ȃ�
	static void erase(int id);

	// �E�����̉摜�̑傫�����擾
	static Vector2 getSpriteSize(int id);

	static Vector2 getSpriteSize(int id, int splitGraphIndex);

	static void finalize();
};

#endif // !SPRITE_H_
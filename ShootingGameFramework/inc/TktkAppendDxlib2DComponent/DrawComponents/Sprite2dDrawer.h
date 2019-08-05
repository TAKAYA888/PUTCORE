#ifndef SPRITE_2D_DRAWER_H_
#define SPRITE_2D_DRAWER_H_

#include <TktkMath/Vector2.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include <TktkAppend2DComponent/Transform2D.h>

// �Q�����摜��`�悷��R���|�[�l���g
// �y�O��R���|�[�l���g�FTransform2D�z
class Sprite2dDrawer
	: public ComponentBase
{
public:

	Sprite2dDrawer(
		float drawPriority,											// �`�悷�郌�C���[�̎��
		int spriteId,												// �`�悷��摜�̎��
		const Vector2& spriteCenterPosRate = Vector2(0.5f, 0.5f)	// �`�悷��摜�̒��S�ʒu�i���� 0.0�`1.0�j
	);

	Sprite2dDrawer(
		float drawPriority,											// �`�悷�郌�C���[�̎��
		int spriteId,												// �`�悷��摜�̎��
		int splitGraphIndex,										// �`�悷��摜�̕����ԍ�
		const Vector2& spriteCenterPosRate = Vector2(0.5f, 0.5f)	// �`�悷��摜�̒��S�ʒu�i���� 0.0�`1.0�j
	);

public:

	void update();
	void draw() const;

public:

	// �X�v���C�gID�̍Đݒ�
	void setSpriteId(int spriteId);

	// �摜�؂蔲���ǂݍ��݂̃X�v���C�gID
	// -1����͂���Ɛ؂蔲�����ɕ`�悷��
	void setSplitGraphIndex(int splitGraphIndex);

	// �X�v���C�g�̒��S���W�i�����j��ݒ�
	void setSpriteCenterPosRate(const Vector2& spriteCenterPosRate = Vector2(0.5f, 0.5f));

	// �X�v���C�g�Ɏg�p����摜��؂蔲���ĕ\�����邩�H
	void useClipping(
		const Vector2& clippingLeftTopPos,		// �؂蔲��������W
		const Vector2& clippingRightBottomPos	// �؂蔲���E�����W
		);

private:

	std::weak_ptr<Transform2D> m_transform2D;

	int m_spriteId{ -1 };

	int m_splitGraphIndex{ -1 };

	Vector2 m_spriteCenterPosRate{ Vector2(0.5f, 0.5f) };

	bool m_useClipping{ false };

	Vector2 m_clippingLeftTopPos{ Vector2::zero };

	Vector2 m_clippingRightBottomPos{ Vector2::one };
};
#endif // !SPRITE_2D_DRAWER_H_
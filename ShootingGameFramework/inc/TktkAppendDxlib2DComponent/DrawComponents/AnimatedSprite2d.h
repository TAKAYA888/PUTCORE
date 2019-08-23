#pragma once

#include <memory>
#include <vector>
#include <TktkMath/Vector2.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include <TktkAppend2DComponent/Transform2D.h>
#include "Sprite2dDrawer.h"

// Sprite2dDrawer�̉摜���A�j���[�V����������
// �y�O��R���|�[�l���g�FSprite2dDrawer�z
class AnimatedSprite2d
	: public ComponentBase
{
public:

	AnimatedSprite2d(
		const std::vector<int>& animationIdList,	// �A�j���[�V�����Ŏg�p����摜�̎�ނ̔z��
		float animationIntervalSec,					// �A�j���[�V�����ŉ摜���؂�ւ��Ԋu�i�b�j
		bool isLoop,								// �A�j���[�V���������[�v�����邩�H
		float animSpeedRate = 1.0f					// �A�j���[�V�����̍Đ��{��
	);

	AnimatedSprite2d(
		int spriteId,									// �A�j���[�V�����Ŏg�p����摜�̎��
		const std::vector<int>& splitGraphIndexList,	// �A�j���[�V�����Ŏg�p����摜�����ԍ��̔z��
		float animationIntervalSec,						// �A�j���[�V�����ŉ摜���؂�ւ��Ԋu�i�b�j
		bool isLoop,									// �A�j���[�V���������[�v�����邩�H
		float animSpeedRate = 1.0f						// �A�j���[�V�����̍Đ��{��
	);

	AnimatedSprite2d(
		int spriteId,					// �A�j���[�V�����Ŏg�p����摜�̎��
		int minSplitGraphIndex,			// �ŏ��̉摜�����ԍ�
		int maxSplitGraphIndex,			// �ő�̉摜�����ԍ�
		float animationIntervalSec,		// �A�j���[�V�����ŉ摜���؂�ւ��Ԋu�i�b�j
		bool isLoop,					// �A�j���[�V���������[�v�����邩�H
		float animSpeedRate = 1.0f		// �A�j���[�V�����̍Đ��{��
	);

public:

	void update();

public:

	void setAnimSpeedRate(float animSpeedRate);

	float getAnimSpeedRate() const;

	void setIsLoop(bool isLoop);

	bool getIsLoop() const;

private:

	std::weak_ptr<Sprite2dDrawer> m_sprite2dDrawer;

	int m_useSpriteId{ -1 };

	std::vector<int> m_animationIdList;

	// �A�j���[�V�����̍Đ����x�{��
	float m_animSpeedRate{ 1.0f };

	// �A�j���[�V�����̌o�ߎ��ԁi�b�j
	float m_animationTimer{ 0.0f };

	// �A�j���[�V�����̍��v���ԁi�b�j
	float m_animationTotalTime{ 0.0f };

	// �A�j���[�V�����Ŏg�p����Î~��P��������̎��ԁi�b�j
	float m_animationIntervalSec;

	bool m_isLoop;

	bool m_useSplitGraphIndex;
};
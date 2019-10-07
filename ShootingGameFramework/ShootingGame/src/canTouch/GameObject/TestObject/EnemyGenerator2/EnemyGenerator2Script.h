#pragma once

#include <string>
#include <forward_list>
#include <TktkIncludePaths.h>
#include "ProjectIncludePaths.h"
#ifndef _MBCS
/*F12�������ăW�����v-> */TktkManual;
/*F12�������ăW�����v-> */ProjectIncludePaths;
#endif

class EnemyGenerator2Script
	: public ComponentBase
{
public:

	EnemyGenerator2Script(const std::string& stageTextPath);

public:

	// ���t���[���Ă΂��
	void update();

private:

	// �o��������G�̏��̍\����
	struct GenerateData
	{
		// ���O
		std::string name;

		// �o������
		float time{ 0.0f };

		// �o�����W
		Vector2 position{ Vector2::zero };

		// �o�����̏����ړ������{���x
		float rotationDeg{ 0.0f };
	};

private:

	// �o��������G�̃f�[�^�̃��X�g
	std::forward_list<GenerateData> m_generateDataList;

	// ���ɏo������G�̃f�[�^���um_generateDataList�v�̂ǂ��ɂ��邩�̏��
	std::forward_list<GenerateData>::iterator m_curIterator;

	// �X�e�[�W���n�܂��Ă���̎���
	float m_spawnTimer{ 0.0f };
};
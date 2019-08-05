#include "EnemyGeneratorScript.h"

#include <vector>
#include "../Enemy/NormalEnemy/NormalEnemy.h"
#include "../Enemy/BossEnemy/BossEnemy.h"

EnemyGeneratorScript::EnemyGeneratorScript(const std::string & stageTextPath)
{
	// �g�p����G�̏o�����̕�������s���ƂɊi�[����z��
	std::vector<std::string> stageTextData;

	// ��������󂯎�����e�L�X�g�t�@�C���̃p�X���g�p���ĕ������ǂݍ���
	FileLoader::fileLoad(stageTextPath, &stageTextData);

	// �ǂݍ��񂾕���������񂷂�
	for (const auto & line : stageTextData)
	{
		// �ǂݍ��񂾍s���J���}��؂�̕�����Ŋi�[����z��
		std::vector<std::string> wordData;

		// �ǂݍ��񂾍s���J���}��؂�Ő؂蕪���Ĕz��ɓ����
		TextSpliter::textSplit(line, ',', &wordData);

		// �o��������G�̏�������
		GenerateData generateData;

		// �ǂݍ��񂾃J���}��؂�̕�����𐔒l�ɕϊ����ēG�̏��ɓK��
		// �ŏ��̐��l���o�����Ԃ�
		generateData.name = wordData.at(0);
		// �Q�Ԗڂ̐��l���o�����Ԃ�
		generateData.time = std::stof(wordData.at(1));
		// �R�A�S�Ԗڂ̐��l���o�����W��
		generateData.position = Vector2(std::stof(wordData.at(2)), std::stof(wordData.at(3)));
		// �T�Ԗڂ̐��l���o����]�p�x
		generateData.rotationDeg = std::stof(wordData.at(4));

		// �o��������G���̃��X�g�ɒǉ�
		m_generateDataList.push_front(generateData);
	}

	// �ǉ������G���̃��X�g���o�����ԏ��Ƀ\�[�g����
	m_generateDataList.sort(
		[](const GenerateData& a, const GenerateData& b) { return a.time < b.time; }
	);

	// ���X�g�ł̎��ɏo������G�̏��̏ꏊ�����X�g�̐擪�̈ʒu�ɂ���
	m_curIterator = std::begin(m_generateDataList);
}

void EnemyGeneratorScript::update()
{
	// �o�ߎ��Ԃ��X�V
	m_spawnTimer += TktkTime::deltaTime();

	// ���X�g�̍Ō�̈ʒu���擾
	auto end = std::end(m_generateDataList);

	/*
	 * ���ɏo������G�̃f�[�^�̈ʒu�����X�g�̗v�f�̍Ō�ł͖����A
	 * ���ɏo������G�̃f�[�^�̏o�����Ԃ����݂̎��Ԃ�����������΃��[�v�𑱂���
	 */
	while (m_curIterator != end && (*m_curIterator).time < m_spawnTimer)
	{
		// ���ɏo������G�̃f�[�^���g�p���ĐV���ȓG���o��������

		// �����o��������G�̖��O��"enemy"��������
		if ((*m_curIterator).name == "enemy")
		{
			// NormalEnemy�𐶐�����
			NormalEnemy::create((*m_curIterator).position, (*m_curIterator).rotationDeg);
		}
		else if ((*m_curIterator).name == "boss")
		{
			BossEnemy::create((*m_curIterator).position, (*m_curIterator).rotationDeg);
		}

		// ���X�g�ł̎��ɏo������G�̏��̏ꏊ����i�߂�
		m_curIterator++;
	}
}
#ifndef MODEL_ASSET_H_
#define MODEL_ASSET_H_

#include <vector>
#include <unordered_map>
#include <string>

#include "ModelHandles.h"

// 3D���f��ID�ƑΉ��������f�����Ǘ�����N���X
class ModelAssets
{
public:

	static void initialize();

	static void finalize();

	// �E������ID�Ɋ���3D���f���f�[�^���֘A�t�����Ă����ꍇ�A�Â��f�[�^���폜���A�V�����f�[�^��ǂݍ���
	// �E�ǂݍ��݂ɐ��������ꍇ�͐^�A���s�����ꍇ�͋U��Ԃ�
	static bool load(int id, const std::string& fileName);

	// �E������ID�Ɋ���3D���f���f�[�^���֘A�t�����Ă����ꍇ�A�Â��f�[�^���폜���A�V�����f�[�^��ǂݍ���
	// �E�ǂݍ��݂ɐ��������ꍇ�͐^�A���s�����ꍇ�͋U��Ԃ�
	// �E�A�j���[�V�����f�[�^�����ǂݍ��ݗp
	static bool load(int id, const std::string& modelFileName, std::vector<std::string> animFileNames);

	// �E������ID��3D���f���f�[�^���֘A�t�����Ă��Ȃ��ꍇ�A�������s��Ȃ�
	static void erase(int id);

	static void eraseAll();

	static const ModelHandles& getModel(int id);

private:

	static std::unordered_map<int, ModelHandles> m_assets;
};

#endif // !MODEL_ASSET_H_
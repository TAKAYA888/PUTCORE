#ifndef MODEL_TEXTURE_ASSETS_H_
#define MODEL_TEXTURE_ASSETS_H_

#include <string>
#include <unordered_map>

// ���f���K���p�̃e�N�X�`��ID�ƑΉ������e�N�X�`�����Ǘ�����N���X
class ModelTextureAssets
{
public:

	static void initialize();

	static void finalize();

	// �E������ID�Ɋ��Ƀ��f���K���p�̃e�N�X�`���f�[�^���֘A�t�����Ă����ꍇ�A�Â��f�[�^���폜���A�V�����f�[�^��ǂݍ���
	// �E�ǂݍ��݂ɐ��������ꍇ�͐^�A���s�����ꍇ�͋U��Ԃ�
	static bool load(int id, const std::string& fileName);

	// �E������ID�Ƀ��f���K���p�̃e�N�X�`���f�[�^���֘A�t�����Ă��Ȃ��ꍇ�A�������s��Ȃ�
	static void erase(int id);

	static void eraseAll();

	static const int getModelTexture(int id);

private:

	static std::unordered_map<int, int> m_assets;
};

#endif // !MODEL_TEXTURE_ASSETS_H_
#ifndef TEXTURE_ASSETS_H_
#define TEXTURE_ASSETS_H_

#include <string>
#include <unordered_map>

#include "TextureHandles.h"

// �e�N�X�`��ID�ƑΉ������e�N�X�`�����Ǘ�����N���X
class TextureAssets
{
public:

	static void initialize();

	static void finalize();

	// �E������ID�Ɋ��Ƀe�N�X�`���f�[�^���֘A�t�����Ă����ꍇ�A�Â��f�[�^���폜���A�V�����f�[�^��ǂݍ���
	// �E�ǂݍ��݂ɐ��������ꍇ�͐^�A���s�����ꍇ�͋U��Ԃ�
	static bool load(int id, const std::string& fileName);

	// �E�摜�̕����ǂݍ���
	// �Erow   �F���ɉ��������邩
	// �Ecolumn�F�c�ɉ��������邩
	// �E���������摜�͍��ォ�珇�ɉE�����ɃC���f�b�N�X���t������
	// �E������ID�Ɋ��Ƀe�N�X�`���f�[�^���֘A�t�����Ă����ꍇ�A�Â��f�[�^���폜���A�V�����f�[�^��ǂݍ���
	// �E�ǂݍ��݂ɐ��������ꍇ�͐^�A���s�����ꍇ�͋U��Ԃ�
	static bool load(int id, const std::string& fileName, int row, int column);

	// �E������ID�Ƀe�N�X�`���f�[�^���֘A�t�����Ă��Ȃ��ꍇ�A�������s��Ȃ�
	static void erase(int id);

	static void eraseAll();

	static const TextureHandles& getTexture(int id);

private:

	static std::unordered_map<int, TextureHandles> m_assets;
};

#endif // !TEXTURE_ASSETS_H_
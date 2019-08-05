#ifndef PIXEL_SHADER_ASSETS_H_
#define PIXEL_SHADER_ASSETS_H_

#include <unordered_map>
#include <string>

class PixelShaderAssets
{
public:

	static void initialize();

	static void finalize();

	// �E������ID�ɃV�F�[�_�[�f�[�^���֘A�t�����Ă����ꍇ�A�Â��f�[�^���폜���A�V�����f�[�^��ǂݍ���
	// �E�ǂݍ��݂ɐ��������ꍇ�͐^�A���s�����ꍇ�͋U��Ԃ�
	static bool load(int id, const std::string& fileName);

	// �E������ID�ɃV�F�[�_�[�f�[�^���֘A�t�����Ă��Ȃ��ꍇ�A�������s��Ȃ�
	static void erase(int id);

	static void eraseAll();

	static const int& getPixelShader(int id);

private:

	static std::unordered_map<int, int> m_assets;
};

#endif // !PIXEL_SHADER_ASSETS_H_

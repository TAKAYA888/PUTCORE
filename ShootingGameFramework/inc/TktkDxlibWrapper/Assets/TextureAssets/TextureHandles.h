#ifndef TEXTURE_HANDLES_H_
#define TEXTURE_HANDLES_H_

#include <vector>

// �����H�摜�ƕ����摜�̃n���h�����i�[����\����
struct TextureHandles
{
public:

	// �����H�摜�̃n���h��
	int graphHandle;

	// ���������摜�̃n���h���̃��X�g
	std::vector<int> splitGraphHandles;
};


#endif // !TEXTURE_HANDLES_H_
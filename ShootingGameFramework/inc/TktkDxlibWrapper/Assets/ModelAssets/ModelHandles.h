#ifndef MODEL_HANDLES_H_
#define MODEL_HANDLES_H_

#include <vector>

// ���f���ƑΉ�����A�j���[�V�����𓯎��Ɋi�[����\����
struct ModelHandles
{
public:

	// ���f���{�̂̃n���h��
	int modellHandle{ -1 };

	// ���f���ɑΉ�����A�j���[�V�����̃n���h��
	std::vector<int> animHandles;
};

#endif // !MODEL_HANDLES_H_
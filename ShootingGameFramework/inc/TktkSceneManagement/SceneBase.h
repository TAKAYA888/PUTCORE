#ifndef BASE_SCENE_H_
#define BASE_SCENE_H_

#include <memory>

// �V�[���̊��N���X
class SceneBase
{
public:

	virtual ~SceneBase();

	// override����ׂ��֐�
public:

	virtual void start() = 0;

	virtual void update() = 0;

	virtual void end() = 0;

	// override���Ă͂����Ȃ��֐�
public:

	// ���̃t���[���̊J�n���ɃV�[����ύX����
	void changeScene(int naxtSceneType);

	// SceneManager�Ŏg�p����֐�
public:

	// �I���t���O��܂�
	void foldTheIsEndFlag();

	// �I���t���O���擾
	bool isEnd();

	// ���̃V�[���̎�ނ��擾
	int getNextSceneType();

private:

	bool m_isEnd{ false };

	int m_naxtSceneType;
};
#endif // !BASE_SCENE_H_
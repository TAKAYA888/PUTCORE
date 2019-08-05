#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

#include <memory>
#include <unordered_map>

class SceneBase;

// �V�[���Ǘ��N���X
class SceneManager
{
public:

	static void initialize();

	// ���݂̏�Ԃ̃V�[�����㏑�������ꍇ�A�Â��V�[���̏I���������s������ɐV�����V�[���̊J�n�������s��
	static void addScene(int sceneType, std::shared_ptr<SceneBase> newScene);

	static void update();

	// ���̃t���[���̊J�n���ɃV�[����ύX����
	static void changeScene(int nextSceneType);

	static void finalize();

private:

	static std::unordered_map<int, std::shared_ptr<SceneBase>> m_sceneMap;

	static int m_curSceneType;
};
#endif // !SCENE_MANAGER_H_
#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

#include <memory>
#include <unordered_map>

class SceneBase;

// シーン管理クラス
class SceneManager
{
public:

	static void initialize();

	// 現在の状態のシーンを上書きした場合、古いシーンの終了処理を行った後に新しいシーンの開始処理を行う
	static void addScene(int sceneType, std::shared_ptr<SceneBase> newScene);

	static void update();

	// 次のフレームの開始時にシーンを変更する
	static void changeScene(int nextSceneType);

	static void finalize();

private:

	static std::unordered_map<int, std::shared_ptr<SceneBase>> m_sceneMap;

	static int m_curSceneType;
};
#endif // !SCENE_MANAGER_H_
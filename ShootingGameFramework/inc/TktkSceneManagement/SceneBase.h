#ifndef BASE_SCENE_H_
#define BASE_SCENE_H_

#include <memory>

// シーンの基底クラス
class SceneBase
{
public:

	virtual ~SceneBase();

	// overrideするべき関数
public:

	virtual void start() = 0;

	virtual void update() = 0;

	virtual void end() = 0;

	// overrideしてはいけない関数
public:

	// 次のフレームの開始時にシーンを変更する
	void changeScene(int naxtSceneType);

	// SceneManagerで使用する関数
public:

	// 終了フラグを折る
	void foldTheIsEndFlag();

	// 終了フラグを取得
	bool isEnd();

	// 次のシーンの種類を取得
	int getNextSceneType();

private:

	bool m_isEnd{ false };

	int m_naxtSceneType;
};
#endif // !BASE_SCENE_H_
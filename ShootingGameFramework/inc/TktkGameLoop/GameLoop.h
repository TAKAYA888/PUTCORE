#ifndef GAME_LOOP_H_
#define GAME_LOOP_H_

#pragma comment(linker, "/entry:mainCRTStartup")

#include <TktkMath/Vector2.h>

// �Q�[�����[�v�N���X
class GameLoop
{
public:

	GameLoop(
		const Vector2& initWindowSize,	// �E�B���h�E�T�C�Y
		bool initFullScreenFlag			// �t���X�N���[���t���O
	);

	virtual ~GameLoop();

	int run();

	GameLoop(const GameLoop& other) = delete;
	GameLoop& operator = (const GameLoop& other) = delete;

public:

	static void exitGame();

private:

	virtual void initalize() = 0;

	virtual void start() = 0;

	virtual void update() = 0;

	virtual void draw() = 0;

	virtual void frameEnd() = 0;

	virtual void end() = 0;

	virtual void finalize() = 0;

protected:

	Vector2 getInitWindowSize() const;
	bool getInitFullScreenFlag() const;

private:

	static bool m_isExit;

private:

	Vector2 m_initWindowSize;

	bool m_initFullScreenFlag;
};

#endif // !GAME_LOOP_H_
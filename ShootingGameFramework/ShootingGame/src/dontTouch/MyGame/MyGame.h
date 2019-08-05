#pragma once

#include <TktkGameLoop/GameLoop.h>
#include <TktkMath/Vector2.h>

class MyGame
	: public GameLoop
{
public:

	MyGame(const Vector2& initWindowSize, bool initFullScreenFlag);

public:

	void initalize() override;

	void start() override;

	void update() override;

	void draw() override;

	void frameEnd() override;

	void end() override;

	void finalize() override;
};
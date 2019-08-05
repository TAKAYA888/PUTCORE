#pragma once

#include "SceneBase.h"

class NullScene
	: public SceneBase
{
public:

	void start() override;

	void update() override;

	void end() override;
};
#pragma once

#include "base_renderer.h"
#include "../models/level.h"

class LevelRenderer : public BaseRenderer
{
public:
	LevelRenderer(const Level& level, SDL_Renderer* renderer);

	virtual void render();

private:
	const Level& _level;
};
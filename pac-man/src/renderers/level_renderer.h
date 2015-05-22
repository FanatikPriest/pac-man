#pragma once

#include <SDL.h>

#include "../models/level.h"

class LevelRenderer
{
public:
	LevelRenderer(const Level& level, SDL_Renderer* renderer);

	void render();

private:
	const Level&  _level;
	SDL_Renderer* _renderer;
};
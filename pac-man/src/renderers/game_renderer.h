#pragma once

#include <SDL.h>

#include "../models/game.h"

class GameRenderer
{
public:
	GameRenderer(const Game& game, SDL_Renderer* renderer);

	void render();

private:
	const Game& _game;
	SDL_Renderer* _renderer;
};
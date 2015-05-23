#pragma once

#include "base_renderer.h"
#include "../models/game.h"

class GameRenderer : public BaseRenderer
{
public:
	GameRenderer(const Game& game, SDL_Renderer* renderer);

	virtual void render();

private:
	const Game& _game;
};
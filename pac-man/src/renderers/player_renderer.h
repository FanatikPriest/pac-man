#pragma once

#include <SDL.h>

#include "../models/player.h"

class PlayerRenderer
{
public:
	PlayerRenderer(const Player& player, SDL_Renderer* renderer);

	void render();

private:
	const Player& _player;
	SDL_Renderer* _renderer;
	bool _display_center_point;

	void render_center_point();
};
#pragma once

#include <SDL.h>

#include "../models/tile.h"

class TileRenderer
{
public:
	TileRenderer(const Tile& tile, SDL_Renderer* renderer);

	void render();

private:
	const Tile&   _tile;
	SDL_Renderer* _renderer;

	void set_color();
};
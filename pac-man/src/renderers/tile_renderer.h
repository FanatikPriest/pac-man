#pragma once

#include "game_object_renderer.h"
#include "../models/tile.h"

class TileRenderer : public GameObjectRenderer
{
public:
	TileRenderer(const Tile& tile, SDL_Renderer* renderer);

protected:
	virtual void set_color();

private:
	const Tile& _tile;
};
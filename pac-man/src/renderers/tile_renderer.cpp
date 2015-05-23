#include "tile_renderer.h"

TileRenderer::TileRenderer(const Tile& tile, SDL_Renderer* renderer)
	: GameObjectRenderer(tile, renderer), _tile(tile)
{}

void TileRenderer::set_color()
{
	if (_tile.is_rigid())
	{
		SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0xFF, 0xFF); // blue
	}
	else
	{
		SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0x00); // white
	}
}
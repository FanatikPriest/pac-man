#include "tile_renderer.h"

TileRenderer::TileRenderer(const Tile& tile, SDL_Renderer* renderer) : _tile(tile)
{
	_renderer = renderer;
}

void TileRenderer::render()
{
	set_color();

	Vector2f position = _tile.get_position();
	Size     size     = _tile.get_size();

	int x = (int)(position.getX() - size.width / 2);
	int y = (int)(position.getY() - size.height / 2);

	SDL_Rect rect = { x, y, (int)size.width, (int)size.height };

	SDL_RenderFillRect(_renderer, &rect);
}

void TileRenderer::set_color()
{
	if (_tile.is_blocking())
	{
		SDL_SetRenderDrawColor(_renderer, 0xFF, 0x00, 0x00, 0xFF); // red
	}
	else
	{
		SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF); // white
	}
}
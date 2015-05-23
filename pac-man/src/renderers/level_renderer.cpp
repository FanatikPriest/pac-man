#include "level_renderer.h"
#include "tile_renderer.h"

LevelRenderer::LevelRenderer(const Level& level, SDL_Renderer* renderer)
	: BaseRenderer(renderer), _level(level)
{}

void LevelRenderer::render()
{
	Tile*** tiles = _level.get_tiles();

	int tile_rows    = _level.get_tile_rows();
	int tile_columns = _level.get_tile_columns();

	for (int i = 0; i < tile_rows; i++)
	{
		for (int j = 0; j < tile_columns; j++)
		{
			TileRenderer tile_renderer(*tiles[i][j], _renderer);

			tile_renderer.render();
		}
	}
}
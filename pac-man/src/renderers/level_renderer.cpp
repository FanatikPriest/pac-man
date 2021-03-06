#include "level_renderer.h"
#include "tile_renderer.h"
#include "collectable_renderer.h"
#include "ghost_renderer.h"
#include "player_renderer.h"

LevelRenderer::LevelRenderer(const Level& level, SDL_Renderer* renderer)
: BaseRenderer(renderer), _level(level)
{}

void LevelRenderer::render()
{
	render_tiles();

	render_pac_dots();

	render_power_ups();

	render_ghosts();

	render_player();
}

void LevelRenderer::render_tiles()
{
	Tile** tiles = _level.get_tiles();

	int tiles_count = _level.get_map().get_tiles_count();

	for (int i = 0; i < tiles_count; i++)
	{
		TileRenderer tile_renderer(*tiles[i], _renderer);

		tile_renderer.render();
	}
}

void LevelRenderer::render_pac_dots()
{
	PacDot** pac_dots = _level.get_pac_dots();

	int pac_dots_count = _level.get_map().get_pac_dots_count();

	for (int i = 0; i < pac_dots_count; i++)
	{
		CollectableRenderer collectable_renderer(*pac_dots[i], _renderer);

		collectable_renderer.render();
	}
}

void LevelRenderer::render_power_ups()
{
	PowerUp** power_ups = _level.get_power_ups();

	int power_ups_count = _level.get_map().get_power_ups_count();

	for (int i = 0; i < power_ups_count; i++)
	{
		CollectableRenderer collectable_renderer(*power_ups[i], _renderer);

		collectable_renderer.render();
	}
}

void LevelRenderer::render_ghosts()
{
	Ghost** ghosts   = _level.get_ghosts();

	int ghosts_count = _level.get_map().get_ghosts_count();

	for (int i = 0; i < ghosts_count; i++)
	{
		GhostRenderer ghost_renderer(*ghosts[i], _renderer);
		ghost_renderer.render();
	}
}

void LevelRenderer::render_player()
{
	PlayerRenderer player_renderer(_level.get_player(), _renderer);
	player_renderer.render();
}
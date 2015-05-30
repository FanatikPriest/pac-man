#include "level.h"

Level::Level() {}

Level::~Level()
{
	delete_ghosts();
	delete_power_ups();
	delete_pac_dots();
	delete_tiles();
}

void Level::delete_map()
{
	for (int i = 0; i < _tile_rows; i++)
	{
		delete[] _map[i];
	}

	delete[] _map;
}

void Level::delete_tiles()
{
	int tiles_count = get_tiles_count();

	for (int i = 0; i < tiles_count; i++)
	{
		delete _tiles[i];
	}

	delete[] _tiles;
}

void Level::delete_pac_dots()
{
	for (int i = 0; i < _pac_dots_count; i++)
	{
		delete _pac_dots[i];
	}

	delete[] _pac_dots;
}

void Level::delete_power_ups()
{
	for (int i = 0; i < _power_ups_count; i++)
	{
		delete _power_ups[i];
	}

	delete[] _power_ups;
}

void Level::delete_ghosts()
{
	for (int i = 0; i < _ghosts_count; i++)
	{
		delete _ghosts[i];
	}

	delete[] _ghosts;
}
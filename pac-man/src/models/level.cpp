#include "level.h"

Level::Level()
{
	_map.initialize();

	_pac_dots_collected  = 0;
	_power_ups_collected = 0;
}

Level::~Level()
{
	delete_ghosts();
	delete_power_ups();
	delete_pac_dots();
	delete_tiles();
}

const Map& Level::get_map() const
{
	return _map;
}

void Level::delete_tiles()
{
	int tiles_count = _map.get_tiles_count();

	for (int i = 0; i < tiles_count; i++)
	{
		delete _tiles[i];
	}

	delete[] _tiles;
}

void Level::delete_pac_dots()
{
	for (int i = 0; i < _map.get_pac_dots_count(); i++)
	{
		delete _pac_dots[i];
	}

	delete[] _pac_dots;
}

void Level::delete_power_ups()
{
	for (int i = 0; i < _map.get_power_ups_count(); i++)
	{
		delete _power_ups[i];
	}

	delete[] _power_ups;
}

void Level::delete_ghosts()
{
	for (int i = 0; i < _map.get_ghosts_count(); i++)
	{
		delete _ghosts[i];
	}

	delete[] _ghosts;
}
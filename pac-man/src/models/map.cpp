#include "map.h"

#include "../utilities/map_loader.h"

Map::Map() {}

void Map::initialize()
{
	load_char_map();
	set_counters();
}

Map::~Map()
{
	delete_char_map();
}

void Map::load_char_map()
{
	_tile_rows_count    = MapLoader::ROWS;
	_tile_columns_count = MapLoader::COLUMNS;

	_char_map = MapLoader::read_map_from_file();
}

void Map::delete_char_map()
{
	for (int i = 0; i < _tile_rows_count; i++)
	{
		delete[] _char_map[i];
	}

	delete[] _char_map;
}

void Map::set_counters()
{
	for (int i = 0; i < _tile_rows_count; i++)
	{
		for (int j = 0; j < _tile_columns_count; j++)
		{
			switch (_char_map[i][j])
			{
				case ('r'):
				{
					_retreat_tiles_count++;
					break;
				}
				case ('g'):
				{
					_ghosts_count++;
					break;
				}
				case ('d'):
				{
					_pac_dots_count++;
					break;
				}
				case ('u'):
				{
					_power_ups_count++;
					break;
				}
			}
		}
	}
}
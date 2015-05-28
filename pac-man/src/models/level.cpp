#include "level.h"

#include "../config/game_settings.h"
#include "../utilities/map_loader.h"

Level::Level()
{
	load_map();

	create_tiles();
	create_pac_dots();
	create_power_ups();
	create_ghosts();

	float x = 14.0f * GameSettings::GAME_OBJECT_SIZE;
	float y = 22.5f * GameSettings::GAME_OBJECT_SIZE;
	create_player(x, y);
}

Level::~Level()
{
	delete_ghosts();
	delete_power_ups();
	delete_pac_dots();
	delete_tiles();
}

void Level::load_map()
{
	_tile_rows    = MapLoader::ROWS;
	_tile_columns = MapLoader::COLUMNS;

	_map = MapLoader::read_map_from_file();
}

void Level::delete_map()
{
	for (int i = 0; i < _tile_rows; i++)
	{
		delete[] _map[i];
	}

	delete[] _map;
}

void Level::create_tiles()
{
	float size = GameSettings::GAME_OBJECT_SIZE;

	int max_retreat_tiles = 4;
	int max_ghost_tiles = 4;

	_tiles         = new Tile*[get_tiles_count()];
	_retreat_tiles = new Tile*[max_retreat_tiles];
	_ghost_tiles   = new Tile*[max_ghost_tiles];

	int tiles_count         = 0;
	int retreat_tiles_count = 0;
	int ghost_tiles_count   = 0;

	for (int i = 0; i < _tile_rows; i++)
	{
		for (int j = 0; j < _tile_columns; j++)
		{
			char symbol   = _map[i][j];
			bool is_rigid = symbol == 'x' || symbol == 'r';

			Tile* new_tile = create_tile(size, size, i, j, is_rigid);

			_tiles[tiles_count] = new_tile;

			tiles_count++;

			if (symbol == 'r' && retreat_tiles_count < max_retreat_tiles)
			{
				_retreat_tiles[retreat_tiles_count] = new_tile;

				retreat_tiles_count++;
			}

			if (symbol == 'g' && ghost_tiles_count < max_ghost_tiles)
			{
				_ghost_tiles[ghost_tiles_count] = new_tile;

				ghost_tiles_count++;
			}
		}
	}
}

Tile* Level::create_tile(float width, float height, int row, int column, bool is_rigid) const
{
	float x = column * height + height / 2.0f;
	float y = row * width + width / 2.0f;


	return new Tile(x, y, height, width, row, column, is_rigid);
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

void Level::create_pac_dots()
{
	float size = GameSettings::PAC_DOT_SIZE;

	int tiles_count = get_tiles_count();

	_pac_dots = new PacDot*[tiles_count];

	_pac_dots_count = 0;
	_pac_dots_collected = 0;

	for (int i = 0; i < _tile_rows; i++)
	{
		for (int j = 0; j < _tile_columns; j++)
		{
			if (_map[i][j] == 'd')
			{
				_pac_dots[_pac_dots_count] = create_pac_dot(size, size, i, j);
				_pac_dots_count++;
			}
		}
	}
}

PacDot* Level::create_pac_dot(float width, float height, int row, int column) const
{
	float tile_size = GameSettings::GAME_OBJECT_SIZE;

	float x = column * tile_size + tile_size / 2.0f;
	float y = row    * tile_size + tile_size / 2.0f;

	return new PacDot(x, y, height, width);
}

void Level::delete_pac_dots()
{
	for (int i = 0; i < _pac_dots_count; i++)
	{
		delete _pac_dots[i];
	}

	delete[] _pac_dots;
}

void Level::create_power_ups()
{
	int max_power_ups = 4;

	float size = GameSettings::POWER_UP_SIZE;

	_power_ups_collected = 0;

	_power_ups = new PowerUp*[max_power_ups];

	_power_ups_count = 0;

	for (int i = 0; i < _tile_rows; i++)
	{
		for (int j = 0; j < _tile_columns; j++)
		{
			if (_map[i][j] != 'u')
			{
				continue;
			}

			_power_ups[_power_ups_count] = create_power_up(size, size, i, j);

			_power_ups_count++;

			if (_power_ups_count == max_power_ups)
			{
				return;
			}
		}
	}
}

PowerUp* Level::create_power_up(float width, float height, int row, int column) const
{
	float tile_size = GameSettings::GAME_OBJECT_SIZE;

	float x = column * tile_size + tile_size / 2.0f;
	float y = row    * tile_size + tile_size / 2.0f;

	return new PowerUp(x, y, height, width);
}

void Level::delete_power_ups()
{
	for (int i = 0; i < _power_ups_count; i++)
	{
		delete _power_ups[i];
	}

	delete[] _power_ups;
}

void Level::create_ghosts()
{
	int max_ghosts = 4;

	_ghosts = new Ghost*[max_ghosts];

	_ghosts_count = 0;

	for (int i = 0; i < _tile_rows; i++)
	{
		for (int j = 0; j < _tile_columns; j++)
		{
			if (_map[i][j] != 'g')
			{
				continue;
			}

			int index = (3 + _ghosts_count) % 4;

			_ghosts[_ghosts_count] = create_ghost(i, j, index);

			_ghosts_count++;

			if (_ghosts_count == max_ghosts)
			{
				return;
			}
		}
	}
}

Ghost* Level::create_ghost(int row, int column, int index) const
{
	float tile_size = GameSettings::GAME_OBJECT_SIZE;

	float x = column * tile_size + tile_size / 2.0f;
	float y = row    * tile_size + tile_size / 2.0f;

	Vector2f position(x, y);
	Size     size(tile_size, tile_size);
	Vector2f direction(0.0f, 0.0f);
	float    speed = GameSettings::GHOST_SPEED;

	return new Ghost(position, size, direction, speed, index);
}
void Level::delete_ghosts()
{
	for (int i = 0; i < _ghosts_count; i++)
	{
		delete _ghosts[i];
	}

	delete[] _ghosts;
}

void Level::create_player(float x = 0.0f, float y = 0.0f)
{
	float object_size = GameSettings::GAME_OBJECT_SIZE;

	Vector2f position(x, y);
	Size     size(object_size, object_size);
	Vector2f direction(0.0f, 0.0f);
	float    speed = GameSettings::PLAYER_SPEED;

	_player = Player(position, size, direction, speed);
}
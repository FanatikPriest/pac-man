#include "level.h"

#include "../application_settings.h"
#include "../utilities/map_loader.h"

Level::Level()
{
	load_map();

	create_tiles();
	create_pac_dots();
	create_power_ups();


	float x = 14.0f * ApplicationSettings::GAME_OBJECT_SIZE;
	float y = 22.5f * ApplicationSettings::GAME_OBJECT_SIZE;
	create_player(x, y);
}

Level::~Level()
{
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
	float size = ApplicationSettings::GAME_OBJECT_SIZE;

	_tiles = new Tile*[get_tiles_count()];

	int count = 0;

	for (int i = 0; i < _tile_rows; i++)
	{
		for (int j = 0; j < _tile_columns; j++)
		{
			_tiles[count] = create_tile(size, size, i, j);

			count++;
		}
	}
}

Tile* Level::create_tile(float width, float height, int row, int column) const
{
	float x = column * height + height / 2.0f;
	float y = row * width + width / 2.0f;

	bool is_rigid = _map[row][column] == 'x';

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
	float size = ApplicationSettings::PAC_DOT_SIZE;

	int tiles_count = get_tiles_count();

	_pac_dots = new PacDot*[tiles_count];

	_pac_dots_count = 0;

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
	float tile_size = ApplicationSettings::GAME_OBJECT_SIZE;

	float x = column * tile_size + tile_size / 2.0f;
	float y = row    * tile_size + tile_size / 2.0f;

	return new PacDot(x, y, height, width);
}

void Level::delete_pac_dots()
{
	int pac_dots_count = get_pac_dots_count();

	for (int i = 0; i < pac_dots_count; i++)
	{
		delete _pac_dots[i];
	}

	delete[] _pac_dots;
}

void Level::create_power_ups()
{
	float size = ApplicationSettings::POWER_UP_SIZE;

	_power_ups = new PowerUp*[get_tiles_count()];

	_power_ups_count = 0;

	for (int i = 0; i < _tile_rows; i++)
	{
		for (int j = 0; j < _tile_columns; j++)
		{
			if (_map[i][j] == 'p')
			{
				_power_ups[_power_ups_count] = create_power_up(size, size, i, j);

				_power_ups_count++;
			}
		}
	}
}

PowerUp* Level::create_power_up(float width, float height, int row, int column) const
{
	float tile_size = ApplicationSettings::GAME_OBJECT_SIZE;

	float x = column * tile_size + tile_size / 2.0f;
	float y = row    * tile_size + tile_size / 2.0f;

	return new PowerUp(x, y, height, width);
}

void Level::delete_power_ups()
{
	int power_ups_count = get_power_ups_count();

	for (int i = 0; i < power_ups_count; i++)
	{
		delete _power_ups[i];
	}

	delete[] _power_ups;
}

void Level::create_player(float x = 0.0f, float y = 0.0f)
{
	float object_size = ApplicationSettings::GAME_OBJECT_SIZE;

	Vector2f position(x, y);
	Size     size(object_size, object_size);
	Vector2f direction(0.0f, 0.0f);
	float    speed = ApplicationSettings::PLAYER_SPEED;

	_player = Player(position, size, direction, speed);
}
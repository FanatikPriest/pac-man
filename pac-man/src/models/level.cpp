#include "level.h"

#include "../application_settings.h"

Level::Level()
{
	create_tiles_map();

	create_tiles();

	create_player(75.0f, 75.0f);
}

Level::~Level()
{
	delete_tiles();

	delete[] _tiles_map;
}

void Level::create_tiles_map()
{
	_tile_rows    = 7;
	_tile_columns = 7;

	_tiles_map = new bool[_tile_rows * _tile_columns] {
		true,  true,  true,  true,  true,  true,  true,
		true,  false, false, false, false, false, true,
		true,  false, true,  false, true,  false, true,
		true,  false, false, false, false, false, true,
		true,  false, true,  false, true,  false, true,
		true,  false, false, false, false, false, true,
		true,  true,  true,  true,  true,  true,  true,
	};
}

void Level::create_tiles()
{
	float size = ApplicationSettings::GAME_OBJECT_SIZE;

	_tiles = new Tile*[get_tiles_count()];

	for (int i = 0; i < _tile_rows; i++)
	{
		for (int j = 0; j < _tile_columns; j++)
		{
			int index = i * _tile_columns + j;

			_tiles[index] = create_tile(size, size, i, j);
		}
	}
}

Tile* Level::create_tile(float width, float height, int row, int column)
{
	float x = row * width + width / 2.0f;
	float y = column * height + height / 2.0f;

	int index = row * _tile_rows + column;

	bool is_rigid = _tiles_map[index];

	return new Tile(x, y, height, width, row, column, is_rigid);
}

void Level::delete_tiles()
{
	for (int i = 0; i < get_tiles_count(); i++)
	{
		delete _tiles[i];
	}

	delete[] _tiles;
}

void Level::create_player(float x = 0.0f, float y = 0.0f)
{
	float object_size = ApplicationSettings::GAME_OBJECT_SIZE;

	Vector2f position(x, y);
	Size     size(object_size, object_size);
	Vector2f direction(0.0f, 0.0f);
	float    speed = ApplicationSettings::PLAYER_SPEED;

	_player = Player(position, size, direction, speed);
	int i = 0;
}
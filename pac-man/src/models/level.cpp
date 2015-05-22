#include "level.h"

Level::Level()
{
	_tile_rows    = 2;
	_tile_columns = 2;

	create_tiles();
}

Level::~Level()
{
	delete_tiles();
}

Tile*** Level::get_tiles() const
{
	return _tiles;
}

void Level::create_tiles()
{
	float size = 50;

	_tiles = new Tile**[_tile_rows];

	for (int i = 0; i < _tile_rows; i++)
	{
		_tiles[i] = new Tile*[_tile_columns];

		for (int j = 0; j < _tile_columns; j++)
		{
			_tiles[i][j] = create_tile(size, size, i, j);
		}
	}
}

Tile* Level::create_tile(float width, float height, int row, int column)
{
	float x = row * width + width / 2.0f;
	float y = column * height + height / 2.0f;

	bool is_blocking = (row + column) % 2 == 0;

	return new Tile(x, y, height, width, row, column, is_blocking);
}

void Level::delete_tiles()
{
	for (int i = 0; i < _tile_rows; i++)
	{
		for (int j = 0; j < _tile_columns; j++)
		{
			delete _tiles[i][j];
		}

		delete [] _tiles[i];
	}

	delete[] _tiles;
}
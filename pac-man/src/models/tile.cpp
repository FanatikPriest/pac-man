#include "tile.h"

Tile::Tile(Vector2f position, Size size, int row, int column, bool is_blocking) : GameObject(position, size)
{
	_row    = row;
	_column = column;
	set_is_blocking(is_blocking);
}

Tile::Tile(float x, float y, float height, float width, int row, int column, bool is_blocking)
: GameObject(x, y, height, width)
{
	_row    = row;
	_column = column;
	set_is_blocking(is_blocking);
}

int Tile::get_row() const
{
	return _row;
}

int Tile::get_column() const
{
	return _column;
}

void Tile::set_is_blocking(bool is_blocking)
{
	_is_blocking = is_blocking;
}

bool Tile::is_blocking() const
{
	return _is_blocking;
}
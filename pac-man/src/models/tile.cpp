#include "tile.h"

Tile::Tile(Vector2f position, Size size, int row, int column, bool is_rigid) : GameObject(position, size, is_rigid)
{
	_row    = row;
	_column = column;
	set_is_rigid(is_rigid);
}

Tile::Tile(float x, float y, float height, float width, int row, int column, bool is_rigid)
: GameObject(x, y, height, width, is_rigid)
{
	_row    = row;
	_column = column;
	set_is_rigid(is_rigid);
}
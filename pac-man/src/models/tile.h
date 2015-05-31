#pragma once

#include "game_object.h"

/*
A level tile that can be rigid. It also keeps its map coordinates (row and column) to optimize
calculations and offsetting.
*/
class Tile : public GameObject
{
public:
	Tile(Vector2f position, Size size, int row, int column, bool is_rigid);
	Tile(float x, float y, float height, float width, int row, int column, bool is_rigid);

	int  get_row() const;
	int  get_column() const;

private:
	int  _row;    // zero-based
	int  _column; // zero-based
};

inline int Tile::get_row() const
{
	return _row;
}

inline int Tile::get_column() const
{
	return _column;
}
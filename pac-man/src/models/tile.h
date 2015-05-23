#pragma once

#include "game_object.h"

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
#pragma once

#include "game_object.h"

class Tile : public GameObject
{
public:
	Tile(Vector2f position, Size size, int row, int column, bool is_blocking);
	Tile(float x, float y, float height, float width, int row, int column, bool is_blocking);

	int  get_row() const;
	int  get_column() const;
	void set_is_blocking(bool is_blocking);
	bool is_blocking() const;

private:
	int  _row;    // zero-based
	int  _column; // zero-based
	bool _is_blocking;
};
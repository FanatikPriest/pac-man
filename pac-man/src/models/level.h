#pragma once

#include "tile.h"

class Level
{
public:
	Level();
	~Level();

	int get_tile_rows() const;
	int get_tile_columns() const;

	Tile*** get_tiles() const;

private:
	int _tile_rows;
	int _tile_columns;

	Tile*** _tiles;

	void  create_tiles();
	Tile* create_tile(float width, float height, int row, int column);
	void  delete_tiles();
};

inline int Level::get_tile_rows() const
{
	return _tile_rows;
}

inline int Level::get_tile_columns() const
{
	return _tile_columns;
}
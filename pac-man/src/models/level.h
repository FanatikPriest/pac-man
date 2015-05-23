#pragma once

#include "tile.h"
#include "player.h"

class Level
{
public:
	Level();
	~Level();

	int get_tile_rows() const;
	int get_tile_columns() const;
	int get_tiles_count() const;

	Tile** get_tiles() const;
	const Player& get_player() const;

private:
	int _tile_rows;
	int _tile_columns;

	bool*   _tiles_map;
	Tile** _tiles;

	Player _player;

	void  create_tiles_map();
	void  create_tiles();
	Tile* create_tile(float width, float height, int row, int column);
	void  delete_tiles();
	void  create_player(float x, float y);

	friend class LevelController;
};

inline int Level::get_tile_rows() const
{
	return _tile_rows;
}

inline int Level::get_tile_columns() const
{
	return _tile_columns;
}

inline Tile** Level::get_tiles() const
{
	return _tiles;
}

inline const Player& Level::get_player() const
{
	return _player;
}

inline int Level::get_tiles_count() const
{
	return _tile_rows * _tile_columns;
}
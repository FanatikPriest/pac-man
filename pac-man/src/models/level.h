#pragma once

#include "tile.h"
#include "pac_dot.h"
#include "power_up.h"
#include "player.h"
#include "../application_settings.h"


class Level
{
public:
	Level();
	~Level();

	int get_tile_rows() const;
	int get_tile_columns() const;
	int get_tiles_count() const;

	Tile** get_tiles() const;
	Tile*  get_tile_at(int x, int y) const;
	Tile*  get_tile_at(Vector2f position) const;

	int      get_pac_dots_count() const;
	PacDot** get_pac_dots() const;
	void     delete_pac_dots();

	PowerUp** get_power_ups() const;

	const Player& get_player() const;


private:
	int _tile_rows;
	int _tile_columns;
	int _pac_dots_count;

	bool*     _tiles_map;
	Tile**    _tiles;
	PacDot**  _pac_dots;
	PowerUp** _power_ups;
	Player    _player;

	void  create_tiles_map();

	void  create_tiles();
	Tile* create_tile(float width, float height, int row, int column) const;
	void  delete_tiles();

	void create_pac_dots();
	PacDot* create_pac_dot(float width, float height, int row, int column) const;

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

inline PacDot** Level::get_pac_dots() const
{
	return _pac_dots;
}

inline PowerUp** Level::get_power_ups() const
{
	return _power_ups;
}

/*
* x and y are zero-based indices.
*/
inline Tile* Level::get_tile_at(int x, int y) const
{
	if (x < 0 || y < 0 || x >= _tile_rows || y >= _tile_columns)
	{
		return NULL;
	}

	int index = x * _tile_columns + y;

	return _tiles[index];
}

inline Tile* Level::get_tile_at(Vector2f position) const
{
	int x = (int) (position.getX() / ApplicationSettings::GAME_OBJECT_SIZE);
	int y = (int) (position.getY() / ApplicationSettings::GAME_OBJECT_SIZE);

	return get_tile_at(x, y);
}

inline const Player& Level::get_player() const
{
	return _player;
}

inline int Level::get_tiles_count() const
{
	return _tile_rows * _tile_columns;
}

inline int Level::get_pac_dots_count() const
{
	return _pac_dots_count;
}
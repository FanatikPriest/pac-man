#pragma once

#include "tile.h"
#include "pac_dot.h"
#include "power_up.h"
#include "ghost.h"
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

	char** get_map() const;

	Tile** get_tiles() const;
	Tile*  get_tile_at(int x, int y) const;
	Tile*  get_tile_at(Vector2f position) const;

	int get_collected_items_count() const;
	int get_collectables_count() const;

	int      get_pac_dots_count() const;
	PacDot** get_pac_dots() const;

	int       get_power_ups_count() const;
	PowerUp** get_power_ups() const;

	int     get_ghosts_count() const;
	Ghost** get_ghosts() const;

	const Player& get_player() const;

	bool has_ghost_collision_occured() const;

private:
	int _tile_rows;
	int _tile_columns;
	int _pac_dots_count;
	int _power_ups_count;
	int _ghosts_count;
	int _pac_dots_collected;
	int _power_ups_collected;

	bool   _has_ghost_collision_occured;

	char** _map;

	Tile**    _tiles;
	PacDot**  _pac_dots;
	PowerUp** _power_ups;
	Ghost**   _ghosts;
	Player    _player;

	void load_map();
	void delete_map();

	void  create_tiles();
	Tile* create_tile(float width, float height, int row, int column) const;
	void  delete_tiles();

	void    create_pac_dots();
	PacDot* create_pac_dot(float width, float height, int row, int column) const;
	void    delete_pac_dots();

	void     create_power_ups();
	PowerUp* create_power_up(float width, float height, int row, int column) const;
	void     delete_power_ups();

	void   create_ghosts();
	Ghost* create_ghost(int row, int column) const;
	void   delete_ghosts();

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

inline char** Level::get_map() const
{
	return _map;
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

inline Ghost** Level::get_ghosts() const
{
	return _ghosts;
}

/*
* x and y are zero-based indices.
*/
inline Tile* Level::get_tile_at(int x, int y) const
{
	if (x < 0 || y < 0 || y >= _tile_columns || x >= _tile_rows)
	{
		return NULL;
	}

	int index = x * _tile_columns + y;

	return _tiles[index];
}

inline Tile* Level::get_tile_at(Vector2f position) const
{
	int x = (int) (position.getY() / ApplicationSettings::GAME_OBJECT_SIZE);
	int y = (int) (position.getX() / ApplicationSettings::GAME_OBJECT_SIZE);

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

inline int Level::get_power_ups_count() const
{
	return _power_ups_count;
}

inline int Level::get_ghosts_count() const
{
	return _ghosts_count;
}

inline int Level::get_collected_items_count() const
{
	return _pac_dots_collected + _power_ups_collected;
}

inline int Level::get_collectables_count() const
{
	return get_pac_dots_count() + get_power_ups_count();
}

inline bool Level::has_ghost_collision_occured() const
{
	return _has_ghost_collision_occured;
}
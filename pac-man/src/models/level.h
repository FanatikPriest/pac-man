#pragma once

#include "map.h"
#include "tile.h"
#include "pac_dot.h"
#include "power_up.h"
#include "ghost.h"
#include "player.h"

#include "../config/game_settings.h"

/*
Contains all game objects.
*/
class Level
{
public:
	Level();
	~Level();

	const Map& get_map() const;

	Tile** get_tiles() const;
	Tile*  get_tile_at(int row, int column) const;
	Tile*  get_tile_at(Vector2f position) const;

	PacDot**  get_pac_dots() const;
	PowerUp** get_power_ups() const;
	Ghost**   get_ghosts() const;

	const Player& get_player() const;

	bool is_player_dead() const;

	int get_collected_items_count() const;

	Vector2f get_retreat_tile_position(int index) const;
	Vector2f get_ghost_initial_tile_position(int index) const;

private:
	Map _map;

	Tile**    _tiles;
	Tile**    _retreat_tiles;
	Tile**    _ghost_tiles;
	PacDot**  _pac_dots;
	PowerUp** _power_ups;
	Ghost**   _ghosts;
	Player    _player;

	int _pac_dots_collected;
	int _power_ups_collected;

	void delete_map();
	void delete_tiles();
	void delete_pac_dots();
	void delete_power_ups();
	void delete_ghosts();

	friend class LevelController;
};

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
* row and column are zero-based indices.
*/
inline Tile* Level::get_tile_at(int row, int column) const
{
	int tile_rows    = _map.get_tile_rows_count();
	int tile_columns = _map.get_tile_columns_count();

	if (row < 0 || column < 0 || row >= tile_rows || column >= tile_columns)
	{
		return NULL;
	}

	int index = row * tile_columns + column;

	return _tiles[index];
}

inline Tile* Level::get_tile_at(Vector2f position) const
{
	int x = (int)(position.getY() / GameSettings::GAME_OBJECT_SIZE);
	int y = (int)(position.getX() / GameSettings::GAME_OBJECT_SIZE);

	return get_tile_at(x, y);
}

inline const Player& Level::get_player() const
{
	return _player;
}

inline int Level::get_collected_items_count() const
{
	return _pac_dots_collected + _power_ups_collected;
}

inline bool Level::is_player_dead() const
{
	return !_player.is_alive();
}

inline Vector2f Level::get_retreat_tile_position(int index) const
{
	return _retreat_tiles[index]->get_position();
}

inline Vector2f Level::get_ghost_initial_tile_position(int index) const
{
	return _ghost_tiles[index]->get_position();
}
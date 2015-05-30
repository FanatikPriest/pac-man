#pragma once

class Map
{
public:
	Map();
	~Map();

	void initialize();

	char** get_char_map() const;

	int get_tile_rows_count() const;
	int get_tile_columns_count() const;
	int get_tiles_count() const;
	int get_retreat_tiles_count() const;
	int get_collectables_count() const;
	int get_pac_dots_count() const;
	int get_power_ups_count() const;
	int get_ghosts_count() const;

private:
	char** _char_map;

	int _tile_rows_count;
	int _tile_columns_count;
	int _retreat_tiles_count;
	int _pac_dots_count;
	int _power_ups_count;
	int _ghosts_count;

	void load_char_map();
	void delete_char_map();

	void set_counters();
};

inline char** Map::get_char_map() const
{
	return _char_map;
}

inline int Map::get_tile_rows_count() const
{
	return _tile_rows_count;
}
inline int Map::get_tile_columns_count() const
{
	return _tile_columns_count;
}

inline int Map::get_tiles_count() const
{
	return _tile_rows_count * _tile_columns_count;
}

inline int Map::get_retreat_tiles_count() const
{
	return _retreat_tiles_count;
}

inline int Map::get_collectables_count() const
{
	return get_pac_dots_count() + get_power_ups_count();
}

inline int Map::get_pac_dots_count() const
{
	return _pac_dots_count;
}

inline int Map::get_power_ups_count() const
{
	return _power_ups_count;
}

inline int Map::get_ghosts_count() const
{
	return _ghosts_count;
}
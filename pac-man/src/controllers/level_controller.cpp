#include "level_controller.h"
#include "ghost_mode_controller.h"

#include "../utilities/collision_detector.h"
#include "../utilities/map_loader.h"

LevelController::LevelController(Level& level) : _level(level) {}

void LevelController::create()
{
	load_map();

	create_tiles();
	create_pac_dots();
	create_power_ups();
	create_ghosts();
	create_player();
}

void LevelController::update()
{
	GhostModeController::update();

	update_player();

	update_ghosts();
}

void LevelController::load_map()
{
	_level._tile_rows    = MapLoader::ROWS;
	_level._tile_columns = MapLoader::COLUMNS;

	_level._map = MapLoader::read_map_from_file();
}

void LevelController::create_tiles()
{
	float size = GameSettings::GAME_OBJECT_SIZE;

	int max_retreat_tiles = 4;
	int max_ghost_tiles   = 4;

	_level._tiles         = new Tile*[_level.get_tiles_count()];
	_level._retreat_tiles = new Tile*[max_retreat_tiles];
	_level._ghost_tiles   = new Tile*[max_ghost_tiles];

	int tiles_count         = 0;
	int retreat_tiles_count = 0;
	int ghost_tiles_count   = 0;

	for (int i = 0; i < _level._tile_rows; i++)
	{
		for (int j = 0; j < _level._tile_columns; j++)
		{
			char symbol   = _level._map[i][j];
			bool is_rigid = symbol == 'x' || symbol == 'r';

			Tile* new_tile = create_tile(size, size, i, j, is_rigid);

			_level._tiles[tiles_count] = new_tile;

			tiles_count++;

			if (symbol == 'r' && retreat_tiles_count < max_retreat_tiles)
			{
				_level._retreat_tiles[retreat_tiles_count] = new_tile;

				retreat_tiles_count++;
			}

			if (symbol == 'g' && ghost_tiles_count < max_ghost_tiles)
			{
				_level._ghost_tiles[ghost_tiles_count] = new_tile;

				ghost_tiles_count++;
			}
		}
	}
}

void LevelController::create_pac_dots()
{
	float size = GameSettings::PAC_DOT_SIZE;

	int tiles_count = _level.get_tiles_count();

	_level._pac_dots = new PacDot*[tiles_count];

	_level._pac_dots_count     = 0;
	_level._pac_dots_collected = 0;

	for (int i = 0; i < _level._tile_rows; i++)
	{
		for (int j = 0; j < _level._tile_columns; j++)
		{
			if (_level._map[i][j] == 'd')
			{
				_level._pac_dots[_level._pac_dots_count] = create_pac_dot(size, size, i, j);
				_level._pac_dots_count++;
			}
		}
	}
}

void LevelController::create_power_ups()
{
	int max_power_ups = 4;

	float size = GameSettings::POWER_UP_SIZE;

	_level._power_ups = new PowerUp*[max_power_ups];

	_level._power_ups_collected = 0;
	_level._power_ups_count     = 0;

	for (int i = 0; i < _level._tile_rows; i++)
	{
		for (int j = 0; j < _level._tile_columns; j++)
		{
			if (_level._map[i][j] != 'u')
			{
				continue;
			}

			_level._power_ups[_level._power_ups_count] = create_power_up(size, size, i, j);

			_level._power_ups_count++;

			if (_level._power_ups_count == max_power_ups)
			{
				return;
			}
		}
	}
}

void LevelController::create_ghosts()
{
	int max_ghosts = 4;

	_level._ghosts = new Ghost*[max_ghosts];

	_level._ghosts_count = 0;

	for (int i = 0; i < _level._tile_rows; i++)
	{
		for (int j = 0; j < _level._tile_columns; j++)
		{
			if (_level._map[i][j] != 'g')
			{
				continue;
			}

			int index = (3 + _level._ghosts_count) % 4;

			_level._ghosts[_level._ghosts_count] = create_ghost(i, j, index);

			_level._ghosts_count++;

			if (_level._ghosts_count == max_ghosts)
			{
				return;
			}
		}
	}
}

void LevelController::create_player()
{
	float x = 14.0f * GameSettings::GAME_OBJECT_SIZE;
	float y = 22.5f * GameSettings::GAME_OBJECT_SIZE;

	float object_size = GameSettings::GAME_OBJECT_SIZE;

	Vector2f position(x, y);
	Size     size(object_size, object_size);
	Vector2f direction(0.0f, 0.0f);
	float    speed = GameSettings::PLAYER_SPEED;

	_level._player = Player(position, size, direction, speed);
}

Tile* LevelController::create_tile(float width, float height, int row, int column, bool is_rigid) const
{
	float x = column * height + height / 2.0f;
	float y = row    * width  + width  / 2.0f;

	return new Tile(x, y, height, width, row, column, is_rigid);
}

PacDot* LevelController::create_pac_dot(float width, float height, int row, int column) const
{
	float tile_size = GameSettings::GAME_OBJECT_SIZE;

	float x = column * tile_size + tile_size / 2.0f;
	float y = row    * tile_size + tile_size / 2.0f;

	return new PacDot(x, y, height, width);
}

PowerUp* LevelController::create_power_up(float width, float height, int row, int column) const
{
	float tile_size = GameSettings::GAME_OBJECT_SIZE;

	float x = column * tile_size + tile_size / 2.0f;
	float y = row    * tile_size + tile_size / 2.0f;

	return new PowerUp(x, y, height, width);
}

Ghost* LevelController::create_ghost(int row, int column, int index) const
{
	float tile_size = GameSettings::GAME_OBJECT_SIZE;

	float x = column * tile_size + tile_size / 2.0f;
	float y = row    * tile_size + tile_size / 2.0f;

	Vector2f position(x, y);
	Size     size(tile_size, tile_size);
	Vector2f direction(0.0f, 0.0f);
	float    speed(GameSettings::GHOST_SPEED);

	return new Ghost(position, size, direction, speed, index);
}

void LevelController::update_player()
{
	Tile* underlying_tile = _level.get_tile_at(_level._player.get_position());

	PlayerController player_controller(_level._player, underlying_tile);
	player_controller.update();

	handle_tile_collisions(player_controller);

	handle_pac_dots_collisions(player_controller);

	handle_power_ups_collisions(player_controller);
}

void LevelController::update_ghosts()
{
	for (int i = 0; i < _level._ghosts_count; i++)
	{
		Ghost* ghost = _level._ghosts[i];

		Tile* underlying_tile = _level.get_tile_at(ghost->get_position());

		GhostController ghost_controller(*ghost, _level, underlying_tile);

		ghost_controller.update();

		handle_tile_collisions(ghost_controller);

		handle_ghost_collision(_level._player, *ghost);
	}
}

void LevelController::handle_tile_collisions(MovingObjectController& moving_object_controller)
{
	int count = _level.get_tiles_count();

	Tile** tiles = _level.get_tiles();

	for (int i = 0; i < count; i++)
	{
		Tile* tile = tiles[i];

		if (CollisionDetector::has_collision(moving_object_controller.get_moving_object(), *tile))
		{
			moving_object_controller.handle_movement_collision(*tile);

			break;
		}
	}
}

void LevelController::handle_pac_dots_collisions(PlayerController& player_controller)
{
	int count = _level.get_pac_dots_count();

	PacDot** pac_dots = _level.get_pac_dots();

	for (int i = 0; i < count; i++)
	{
		PacDot* pac_dot = pac_dots[i];

		if (CollisionDetector::has_collision(_level._player, *pac_dot))
		{
			player_controller.handle_collectable_collision(*pac_dot);

			_level._pac_dots_collected++;

			break;
		}
	}
}

void LevelController::handle_power_ups_collisions(PlayerController& player_controller)
{
	int count = _level.get_power_ups_count();

	PowerUp** power_ups = _level.get_power_ups();

	for (int i = 0; i < count; i++)
	{
		PowerUp* power_up = power_ups[i];

		if (CollisionDetector::has_collision(_level._player, *power_up))
		{
			player_controller.handle_collectable_collision(*power_up);

			_level._power_ups_collected++;

			GhostModeController::set_current_mode(GhostMode::FRIGHTENED);

			break;
		}
	}
}

void LevelController::handle_ghost_collision(Player& player, Ghost& ghost)
{
	if (!CollisionDetector::has_collision(player, ghost))
	{
		return;
	}

	GhostMode ghost_mode = ghost.get_mode();

	if (ghost_mode == GhostMode::FRIGHTENED)
	{
		ghost.set_mode(GhostMode::EATEN);
	}
	else if (ghost_mode == GhostMode::CHASE || ghost_mode == GhostMode::SCATTER)
	{
		player.set_is_alive(false);
	}
}
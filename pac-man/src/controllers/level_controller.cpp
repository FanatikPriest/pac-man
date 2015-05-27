#include "level_controller.h"
#include "ghost_mode_controller.h"
#include "../utilities/collision_detector.h"

LevelController::LevelController(Level& level) : _level(level) {}

void LevelController::update()
{
	GhostModeController::update();

	update_player();

	update_ghosts();
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

			break;
		}
	}
}

bool LevelController::handle_ghost_collision(const Player& player, const Ghost& ghost)
{
	bool result = CollisionDetector::has_collision(player, ghost);

	_level._has_ghost_collision_occured = _level._has_ghost_collision_occured || result;

	return result;
}
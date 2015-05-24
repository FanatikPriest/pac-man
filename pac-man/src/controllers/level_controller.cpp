#include "level_controller.h"
#include "../utilities/collision_detector.h"

LevelController::LevelController(Level& level) : _level(level) {}

void LevelController::update()
{
	Tile* underlying_tile = _level.get_tile_at(_level._player.get_position());

	PlayerController player_controller(_level._player, underlying_tile);
	player_controller.update();

	handle_tile_collisions(player_controller);

	handle_pac_dots_collisions(player_controller);

	handle_power_ups_collisions(player_controller);
}

void LevelController::handle_tile_collisions(PlayerController& player_controller)
{
	int count = _level.get_tiles_count();

	Tile** tiles = _level.get_tiles();

	for (int i = 0; i < count; i++)
	{
		Tile* tile = tiles[i];

		if (CollisionDetector::has_collision(_level._player, *tile))
		{
			player_controller.handle_movement_collision(*tile);

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
		}
	}

}
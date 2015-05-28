#pragma once

#include "../models/level.h"
#include "player_controller.h"
#include "ghost_controller.h"

class LevelController
{
public:
	LevelController(Level& level);

	void update();

private:
	Level& _level;

	void update_player();
	void update_ghosts();

	void handle_tile_collisions(MovingObjectController& moving_object_controller);
	void handle_pac_dots_collisions(PlayerController& player_controller);
	void handle_power_ups_collisions(PlayerController& player_controller);
	void handle_ghost_collision(Player& player, Ghost& ghost);
};
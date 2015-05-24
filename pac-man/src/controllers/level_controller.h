#pragma once

#include "../models/level.h"
#include "player_controller.h"

class LevelController
{
public:
	LevelController(Level& level);

	void update();

private:
	Level& _level;

	void handle_tile_collisions(PlayerController& player_controller);
	void handle_pac_dots_collisions(PlayerController& player_controller);
	void handle_power_ups_collisions(PlayerController& player_controller);
};
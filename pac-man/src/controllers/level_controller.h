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
};
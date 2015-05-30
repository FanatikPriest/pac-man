#pragma once

#include "../models/level.h"
#include "player_controller.h"
#include "ghost_controller.h"

class LevelController
{
public:
	LevelController(Level& level);

	void create();

	void update();

private:
	Level& _level;

	void load_map();

	void create_tiles();
	void create_pac_dots();
	void create_power_ups();
	void create_ghosts();
	void create_player();

	Tile*    create_tile(float width, float height, int row, int column, bool is_rigid) const;
	PacDot*  create_pac_dot(float width, float height, int row, int column) const;
	PowerUp* create_power_up(float width, float height, int row, int column) const;
	Ghost*   create_ghost(int row, int column, int index) const;

	void update_player();
	void update_ghosts();

	void handle_tile_collisions(MovingObjectController& moving_object_controller);
	void handle_pac_dots_collisions(PlayerController& player_controller);
	void handle_power_ups_collisions(PlayerController& player_controller);
	void handle_ghost_collision(Player& player, Ghost& ghost);
};
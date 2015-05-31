#pragma once

#include "../models/level.h"
#include "player_controller.h"
#include "ghost_controller.h"

/*
Controls the level and its game objects, handles actions on collisions.
*/
class LevelController
{
public:
	LevelController(Level& level);

	void create();

	void update();

private:
	Level& _level;

	void create_game_obejcts();

	Tile*    create_tile(int row, int column, bool is_rigid) const;
	PacDot*  create_pac_dot(int row, int column) const;
	PowerUp* create_power_up(int row, int column) const;
	Ghost*   create_ghost(int row, int column, int index) const;
	void     create_player(int row, int column);

	void update_player();
	void update_ghosts();

	void handle_tile_collisions(MovingObjectController& moving_object_controller);
	void handle_pac_dots_collisions(PlayerController& player_controller);
	void handle_power_ups_collisions(PlayerController& player_controller);
	void handle_ghost_collision(Player& player, Ghost& ghost);

	Vector2f determine_game_object_position(int row, int column) const;
};
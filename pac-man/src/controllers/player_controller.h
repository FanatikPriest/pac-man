#pragma once

#include "../models/player.h"
#include "../models/tile.h"
#include "../models/pac_dot.h"

class PlayerController
{
public:
	PlayerController(Player& player, Tile* underlying_tile);

	void update();

	void handle_movement_collision(const Tile& tile);
	void handle_pac_dot_collision(PacDot& pac_dot);

private:
	Player& _player;
	Tile*   _underlying_tile;

	void move_player();
	bool set_direction(const Vector2f& direction);
};
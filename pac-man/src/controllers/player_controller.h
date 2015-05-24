#pragma once

#include "../models/player.h"
#include "../models/tile.h"

class PlayerController
{
public:
	PlayerController(Player& player, Tile* underlying_tile);

	void update();

	void handle_movement_collision(const GameObject& game_object);

private:
	Player& _player;
	Tile*   _underlying_tile;

	void move_player();
	bool set_direction(const Vector2f& direction);
};
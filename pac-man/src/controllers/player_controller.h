#pragma once

#include "../models/player.h"

class PlayerController
{
public:
	PlayerController(Player& player);

	void update();

	void handle_movement_collision(const GameObject& game_object);

private:
	Player& _player;
};
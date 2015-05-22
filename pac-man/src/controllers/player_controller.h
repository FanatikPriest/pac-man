#pragma once

#include "../models/player.h"

class PlayerController
{
public:
	PlayerController(Player& player);

	void update();

private:
	Player& _player;
};
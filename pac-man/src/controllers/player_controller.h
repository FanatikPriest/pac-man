#pragma once

#include "moving_object_controller.h"

#include "../models/player.h"
#include "../models/collectable.h"

class PlayerController : public MovingObjectController
{
public:
	PlayerController(Player& player, Tile* underlying_tile);

	void handle_collectable_collision(Collectable& collectable);

protected:
	virtual void move_object();

private:
	Player& _player;
};
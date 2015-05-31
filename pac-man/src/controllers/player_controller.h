#pragma once

#include "moving_object_controller.h"

#include "../models/player.h"
#include "../models/collectable.h"

/*
Handles player movement specifics and collisions with collectable items.
*/
class PlayerController : public MovingObjectController
{
public:
	PlayerController(Player& player, Tile* underlying_tile);

	void handle_collectable_collision(Collectable& collectable);

protected:
	virtual void move_object();

	Vector2f determine_new_direction();

private:
	Player& _player;
};
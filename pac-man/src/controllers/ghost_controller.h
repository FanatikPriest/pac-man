#pragma once

#include "moving_object_controller.h"

#include "../models/ghost.h"
#include "../models/level.h"

class GhostController : public MovingObjectController
{
public:
	GhostController(Ghost& ghost, const Level& level, Tile* underlying_tile);

protected:
	virtual void move_object();

private:
	Ghost& _ghost;
	const Level& _level;

	void      set_target();
	Vector2f  determine_next_target() const;
	Vector2f* get_adjecent_tile_positions() const;
	void      change_ghost_direction();
	Vector2f  get_tile_position_at(int x, int y) const;
};
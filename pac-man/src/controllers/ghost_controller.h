#pragma once

#include "moving_object_controller.h"

#include "../models/ghost.h"
#include "../models/level.h"

class GhostController : public MovingObjectController
{
public:
	GhostController(Ghost& ghost, const Level& level, Tile* underlying_tile);

	virtual void update();

private:
	Ghost& _ghost;
	const Level& _level;

	void      set_mode();
	void      set_target();
	Vector2f  determine_next_target() const;
	Vector2f* get_adjecent_tile_positions() const;
	Vector2f  determine_ultimate_target() const;
	void      change_ghost_direction();
	Vector2f  get_tile_position_at(int x, int y) const;
};
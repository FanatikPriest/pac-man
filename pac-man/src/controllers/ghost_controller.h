#pragma once

#include "moving_object_controller.h"

#include "../models/ghost.h"

class GhostController : public MovingObjectController
{
public:
	GhostController(Ghost& ghost, Tile* underlying_tile);

protected:
	virtual void move_object();

private:
	Ghost& _ghost;
};
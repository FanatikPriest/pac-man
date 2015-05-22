#pragma once

#include "../models/moving_object.h"

class MovingObjectController
{
public:
	MovingObjectController(MovingObject& moving_object);

	void update();

private:
	MovingObject& _moving_object;
};
#pragma once

#include "moving_object.h"

class Ghost : public MovingObject
{
public:
	Ghost();
	Ghost(Vector2f position, Size size, Vector2f direction, float speed);

	friend class GhostController;
	friend class GhostRenderer;
};
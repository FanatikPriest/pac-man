#pragma once

#include "moving_object.h"

class Player : public MovingObject
{
public:
	Player();
	Player(Vector2f position, Size size, Vector2f direction, float speed);
};
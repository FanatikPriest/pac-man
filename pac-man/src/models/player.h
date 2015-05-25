#pragma once

#include "moving_object.h"
#include "score.h"

class Player : public MovingObject
{
public:
	Player();
	Player(Vector2f position, Size size, Vector2f direction, float speed);

private:
	Score _score;

	friend class PlayerController;
	friend class PlayerRenderer;
};
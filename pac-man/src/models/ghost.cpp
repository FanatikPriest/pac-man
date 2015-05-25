#include "ghost.h"

Ghost::Ghost() : MovingObject() {}

Ghost::Ghost(Vector2f position, Size size, Vector2f direction, float speed)
	: MovingObject(position, size, true, direction, speed)
{}
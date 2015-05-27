#include "ghost.h"

Ghost::Ghost() : MovingObject()
{
	_index = 0;
	set_mode(GhostMode::SCATTER);
}

Ghost::Ghost(Vector2f position, Size size, Vector2f direction, float speed, int index)
	: MovingObject(position, size, true, direction, speed), _index(index)
{
	set_mode(GhostMode::SCATTER);
}
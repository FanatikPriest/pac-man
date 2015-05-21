#include "moving_object.h"

MovingObject::MovingObject() : GameObject()
{
	float zero = 0.0f;

	set_direction(zero, zero);
	set_speed(zero);
}

MovingObject::MovingObject(Vector2f position, Size size, Vector2f direction, float speed) : GameObject(position, size)
{
	set_direction(direction);
	set_speed(speed);
}

MovingObject::MovingObject(float x, float y, float height, float width, float dx, float dy, float speed)
	: GameObject(x, y, height, width)
{
	set_direction(dx, dy);
	set_speed(speed);
}
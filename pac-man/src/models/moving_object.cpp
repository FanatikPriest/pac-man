#include "moving_object.h"

MovingObject::MovingObject() : GameObject()
{
	float zero = 0.0f;

	set_direction(zero, zero);
	set_speed(zero);
}

MovingObject::MovingObject(Vector2f position, Size size, Vector2f direction, float speed, bool is_rigid)
	: GameObject(position, size, is_rigid)
{
	set_direction(direction);
	set_speed(speed);
}

MovingObject::MovingObject(float x, float y, float height, float width, float dx, float dy, float speed, bool is_rigid)
	: GameObject(x, y, height, width, is_rigid)
{
	set_direction(dx, dy);
	set_speed(speed);
}

void MovingObject::move()
{
	Vector2f position = get_position() + (get_direction() * get_speed() * Delta::get());

	set_position(position);
}
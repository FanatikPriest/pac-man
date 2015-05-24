#pragma once

#include "game_object.h"
#include "../utilities/delta.h"

/*
* A game object with position, size (see GameObject), movement direction and movement speed.
*/
class MovingObject : public GameObject
{
public:
	MovingObject();
	MovingObject(Vector2f position, Size size, Vector2f direction, float speed, bool is_rigid);
	MovingObject(float x, float y, float height, float width, float dx, float dy, float speed, bool is_rigid);
	
	Vector2f get_direction() const;
	void     set_direction(Vector2f direction);
	void     set_direction(float dx, float dy);
	float    get_speed() const;
	void     set_speed(float speed);

	void move();
	
private:
	Vector2f _direction;
	float    _speed;
};

// Inline function definitions:

inline Vector2f MovingObject::get_direction() const
{
	return _direction;
}

inline void MovingObject::set_direction(Vector2f direction)
{
	set_direction(direction.getX(), direction.getY());
}

inline void MovingObject::set_direction(float dx, float dy)
{
	_direction = Vector2f(dx, dy);
	_direction.normalize();
}

inline float MovingObject::get_speed() const
{
	return _speed;
}

inline void MovingObject::set_speed(float speed)
{
	_speed = speed;
}
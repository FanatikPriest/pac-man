#pragma once

#include "moving_object.h"

class Ghost : public MovingObject
{
public:
	Ghost();
	Ghost(Vector2f position, Size size, Vector2f direction, float speed);

	void     set_target(const Vector2f target);
	Vector2f get_target() const;

private:
	Vector2f _target;

	friend class GhostController;
	friend class GhostRenderer;
};

inline void Ghost::set_target(const Vector2f target)
{
	_target = target;
}

inline Vector2f Ghost::get_target() const
{
	return _target;
}
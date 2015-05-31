#pragma once

#include "moving_object.h"
#include "../enums/ghost_mode.h"

/*
The ghost has a ghost mode which changes its movement behaviour. The target of the ghost
is the next position that is closest to its ultimate target. The ultimate target is defined
based in the current ghost mode.
*/
class Ghost : public MovingObject
{
public:
	Ghost();
	Ghost(Vector2f position, Size size, Vector2f direction, float speed, int index);

	int get_index() const;

	void     set_target(const Vector2f target);
	Vector2f get_target() const;

	void      set_mode(GhostMode mode);
	GhostMode get_mode() const;

private:
	int       _index;
	Vector2f  _target;
	GhostMode _mode;
};

inline int Ghost::get_index() const
{
	return _index;
}

inline void Ghost::set_target(const Vector2f target)
{
	_target = target;
}

inline Vector2f Ghost::get_target() const
{
	return _target;
}

inline void Ghost::set_mode(GhostMode mode)
{
	_mode = mode;
}

inline GhostMode Ghost::get_mode() const
{
	return _mode;
}
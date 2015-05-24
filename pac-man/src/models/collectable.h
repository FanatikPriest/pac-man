#pragma once

#include "game_object.h"

class Collectable : public GameObject
{
public:
	Collectable();
	Collectable(Vector2f position, Size size, bool is_rigid);
	Collectable(float x, float y, float height, float width, bool is_rigid);

	bool is_collected() const;
	void set_collected(const bool is_collected);

private:
	bool _is_collected;
};

inline bool Collectable::is_collected() const
{
	return _is_collected;
}

inline void Collectable::set_collected(const bool is_collected)
{
	_is_collected = is_collected;

	set_is_rigid(!is_collected);
}
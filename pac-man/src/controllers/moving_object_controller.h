#pragma once

#include "../models/moving_object.h"
#include "../models/tile.h"

/*
Moves the object and handles its collisions with tiles.
*/
class MovingObjectController
{
public:
	MovingObjectController(MovingObject& moving_object, Tile* underlying_tile);

	const MovingObject& get_moving_object() const;

	virtual void update();

	void handle_movement_collision(const Tile& tile);

	bool set_direction(const Vector2f& direction);

protected:
	Tile* _underlying_tile;

	virtual void move_object();

private:
	MovingObject& _moving_object;
};

inline const MovingObject& MovingObjectController::get_moving_object() const
{
	return _moving_object;
}
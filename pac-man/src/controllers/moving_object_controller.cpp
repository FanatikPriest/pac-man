#include "moving_object_controller.h"

MovingObjectController::MovingObjectController(MovingObject& moving_object, Tile* underlying_tile)
	: _moving_object(moving_object), _underlying_tile(underlying_tile)
{}

void MovingObjectController::update()
{
	move_object();
}

void MovingObjectController::move_object()
{
	_moving_object.move();
}

/*
Moves back the moving object so that it and the tile it collides with are next to each other.
*/
void MovingObjectController::handle_movement_collision(const Tile& tile)
{
	SDL_Rect intersection;

	SDL_IntersectRect(&_moving_object.get_bounding_box(), &tile.get_bounding_box(), &intersection);

	Vector2f reversed_direction = _moving_object.get_direction() * -1.0f;

	Vector2f offset(intersection.w * reversed_direction.getX(), intersection.h * reversed_direction.getY());

	_moving_object.set_position(_moving_object.get_position() + offset);
}

/*
Returns true if the new direction differs from the last. False otherwise.
*/
bool MovingObjectController::set_direction(const Vector2f& direction)
{
	bool direction_changed = !(direction == _moving_object.get_direction());

	_moving_object.set_direction(direction);

	return direction_changed;
}
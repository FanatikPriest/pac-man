#include "player_controller.h"
#include "../utilities/directions.h"
#include "../keyboard_handler.h"

PlayerController::PlayerController(Player& player, Tile* underlying_tile) : _player(player), _underlying_tile(underlying_tile) {}

void PlayerController::update()
{
	move_player();
}

void PlayerController::handle_movement_collision(const Tile& tile)
{
	SDL_Rect intersection;

	SDL_IntersectRect(&_player.get_bounding_box(), &tile.get_bounding_box(), &intersection);

	Vector2f reversed_direction = _player.get_direction() * -1.0f;

	Vector2f offset(intersection.w * reversed_direction.getX(), intersection.h * reversed_direction.getY());

	_player.set_position(_player.get_position() + offset);
}

void PlayerController::handle_collectable_collision(Collectable& collectable)
{
	collectable.set_collected(true);
	_player._score.add();
}

void PlayerController::move_player()
{
	KeyboardHandler& keyboard      = KeyboardHandler::get_instance();
	Vector2f&        new_direction = _player.get_direction();

	if (keyboard.up == SDL_PRESSED)
	{
		new_direction = Directions::UP;
	}
	else if (keyboard.left == SDL_PRESSED)
	{
		new_direction = Directions::LEFT;
	}
	else if (keyboard.down == SDL_PRESSED)
	{
		new_direction = Directions::DOWN;
	}
	else if (keyboard.right == SDL_PRESSED)
	{
		new_direction = Directions::RIGHT;
	}

	bool direction_changed = set_direction(new_direction);

	if (direction_changed && _underlying_tile)
	{
		_player.set_position(_underlying_tile->get_position());
	}

	_player.move();
}

bool PlayerController::set_direction(const Vector2f& direction)
{
	bool direction_changed = !(direction == _player.get_direction());

	_player.set_direction(direction);

	return direction_changed;
}
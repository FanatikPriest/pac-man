#include "player_controller.h"
#include "../utilities/directions.h"
#include "../keyboard_handler.h"

PlayerController::PlayerController(Player& player, Tile* underlying_tile)
	: MovingObjectController(player, underlying_tile), _player(player)
{}

void PlayerController::handle_collectable_collision(Collectable& collectable)
{
	collectable.set_collected(true);
	_player._score.add();
}

void PlayerController::move_object()
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

	MovingObjectController::move_object();
}
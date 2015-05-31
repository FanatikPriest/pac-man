#include "player_controller.h"
#include "../utilities/directions.h"
#include "../utilities/keyboard_handler.h"

PlayerController::PlayerController(Player& player, Tile* underlying_tile)
	: MovingObjectController(player, underlying_tile), _player(player)
{}

/*
Collects the collectable item and updates the score on collision with a collectable item.
*/
void PlayerController::handle_collectable_collision(Collectable& collectable)
{
	collectable.set_collected(true);
	_player.get_score().add();
}

/*
Sets player's new direction. If the new direction differs from the last, the player is repositioned
on the center of the underlying tile. This helps with taking turns.
*/
void PlayerController::move_object()
{
	Vector2f new_direction = determine_new_direction();

	bool direction_changed = set_direction(new_direction);

	if (direction_changed && _underlying_tile)
	{
		_player.set_position(_underlying_tile->get_position());
	}

	MovingObjectController::move_object();
}

/*
Determines a new direction for the player based on the pressed keyboard buttons.
*/
Vector2f PlayerController::determine_new_direction()
{
	KeyboardHandler& keyboard      = KeyboardHandler::get_instance();
	Vector2f         new_direction = _player.get_direction();

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

	return new_direction;
}
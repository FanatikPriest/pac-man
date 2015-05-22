#include "movement_handler.h"

const float MovementHandler::zero = 0.0f;
const float MovementHandler::one  = 1.0f;

const Vector2f MovementHandler::up    = Vector2f(zero, -one);
const Vector2f MovementHandler::down  = Vector2f(zero, one);
const Vector2f MovementHandler::left  = Vector2f(-one, zero);
const Vector2f MovementHandler::right = Vector2f(one,  zero);

void MovementHandler::move_player(Player& player)
{
	KeyboardHandler& keyboard = KeyboardHandler::get_instance();

	if (keyboard.up == SDL_PRESSED)
	{
		player.set_direction(up);
		player.move();
	}

	if (keyboard.left == SDL_PRESSED)
	{
		player.set_direction(left);
		player.move();
	}

	if (keyboard.down == SDL_PRESSED)
	{
		player.set_direction(down);
		player.move();
	}

	if (keyboard.right == SDL_PRESSED)
	{
		player.set_direction(right);
		player.move();
	}
}
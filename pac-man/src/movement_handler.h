#pragma once

#include <SDL.h>

#include "models/player.h"
#include "keyboard_handler.h"

class MovementHandler
{
public:
	static void move_player(Player& player);

private:
	static const float zero;
	static const float one;

	static const Vector2f up;
	static const Vector2f down;
	static const Vector2f left;
	static const Vector2f right;
};
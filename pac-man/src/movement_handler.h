#pragma once

#include <SDL.h>

#include "models/player.h"
#include "keyboard_handler.h"

class MovementHandler
{
public:
	static const Vector2f up;
	static const Vector2f down;
	static const Vector2f left;
	static const Vector2f right;
private:
	static const float zero;
	static const float one;
};
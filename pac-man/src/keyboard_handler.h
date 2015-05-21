#pragma once

#include <SDL.h>

// Handles the keyboard buttons that set the direction of movement
class KeyboardHandler
{
public:
	static KeyboardHandler& get_instance()
	{
		static KeyboardHandler* instance;

		if (instance == NULL)
		{
			instance = new KeyboardHandler();
		}

		return *instance;
	}

	Uint8 up, down, left, right;

private:
	KeyboardHandler()
	{
		up = down = left = right = SDL_RELEASED;
	}

	KeyboardHandler(KeyboardHandler&);
	KeyboardHandler& operator=(const KeyboardHandler&);
};
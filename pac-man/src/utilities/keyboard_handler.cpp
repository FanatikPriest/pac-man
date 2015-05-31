#include <SDL.h>

#include "keyboard_handler.h"

KeyboardHandler::KeyboardHandler()
{
	up = down = left = right = SDL_RELEASED;
}

KeyboardHandler& KeyboardHandler::get_instance()
{
	static KeyboardHandler* instance;

	if (instance == NULL)
	{
		instance = new KeyboardHandler();
	}

	return *instance;
}

void KeyboardHandler::update_states(const SDL_Event& event)
{
	KeyboardHandler& keyboard = KeyboardHandler::get_instance();

	switch (event.key.keysym.scancode)
	{
		case SDL_SCANCODE_UP:
		{
			keyboard.up = event.key.state;
			break;
		}
		case SDL_SCANCODE_DOWN:
		{
			keyboard.down = event.key.state;
			break;
		}
		case SDL_SCANCODE_LEFT:
		{
			keyboard.left = event.key.state;
			break;
		}
		case SDL_SCANCODE_RIGHT:
		{
			keyboard.right = event.key.state;
			break;
		}
	}
}
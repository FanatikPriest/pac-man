#pragma once

// Handles the keyboard buttons that set the direction of movement
class KeyboardHandler
{
public:
	static KeyboardHandler& get_instance();

	static void update_states(const SDL_Event& event);

	Uint8 up, down, left, right;

private:
	KeyboardHandler();
	KeyboardHandler(KeyboardHandler&);
	KeyboardHandler& operator=(const KeyboardHandler&);
};
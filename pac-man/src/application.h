#pragma once

#include <SDL.h>

class Application
{
public:
	Application();

	int on_execute(); // executes the SDL application

private:
	bool          _is_running;
	SDL_Window*   _window;
	SDL_Renderer* _renderer;

	bool on_init();						   // initializes the application data
	void on_event(const SDL_Event& event); // handles keyboard events as well as some SDL-specific events
	void on_loop();						   // calculates the game objects' data
	void on_render();					   // renders the game objects in the window
	void on_cleanup();					   // cleans up some date before the application terminates
};
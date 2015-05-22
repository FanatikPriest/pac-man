#pragma once

#include <SDL.h>

#include "models/game.h"

class Application
{
public:
	Application();

	int execute(); // executes the SDL application

private:
	bool          _is_running;
	SDL_Window*   _window;
	SDL_Renderer* _renderer;

	Game _game;

	bool initialize();							// initializes the application data
	void handle_events(const SDL_Event& event); // handles keyboard events as well as some SDL-specific events
	void update();								// calculates the game objects' data
	void render();								// renders the game objects in the window
	void cleanup();								// cleans up some date before the application terminates
};
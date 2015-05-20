#include "SDL.h"

int main(int, char**) {
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* sdlWindow = SDL_CreateWindow("Pac-Man",
											SDL_WINDOWPOS_CENTERED,
											SDL_WINDOWPOS_CENTERED,
											800, 600,
											SDL_WINDOW_SHOWN);
	bool running = true;
	SDL_Event event;

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYUP || event.type == SDL_KEYDOWN)
			{
				running = false;
			}
		}
	}

	SDL_Quit();

	return 0;
}
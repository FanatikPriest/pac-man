#include "application.h"
#include "window_settings.h"
#include "keyboard_handler.h"

Application::Application()
{
	_is_running     = true;
	_window         = NULL;
	_renderer       = NULL;
}

int Application::on_execute()
{
	if (on_init() == false)
	{
		return -1;
	}

	SDL_Event event;

	while (_is_running)
	{
		while (SDL_PollEvent(&event))
		{
			on_event(event);
		}

		on_loop();
		on_render();
	}

	on_cleanup();

	return 0;
}

bool Application::on_init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}

	_window = SDL_CreateWindow("Pac-Man",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								WindowSettings::WINDOW_WIDTH,
								WindowSettings::WINDOW_HEIGHT,
								SDL_WINDOW_SHOWN);

	if (_window == NULL)
	{
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	return true;
}

void Application::on_event(const SDL_Event& event)
{
	switch (event.type)
	{
		case SDL_QUIT:
		{
			_is_running = false;
			break;
		}
		case SDL_KEYDOWN:
		case SDL_KEYUP:
		{
			KeyboardHandler::update_states(event);

			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				_is_running = false;
			}

			break;
		}
	}
}

void Application::on_loop()
{

}

void Application::on_render()
{
	// fill with black to wipe previous frame
	SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(_renderer);

	// render a filled quad
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0x00, 0xFF);
	SDL_Rect rect = { 10, 10, 100, 100 };
	SDL_RenderFillRect(_renderer, &rect);

	// update the surface with this frame's graphics
	SDL_RenderPresent(_renderer);
}

void Application::on_cleanup()
{
	SDL_DestroyWindow(_window);

	SDL_Quit();
}
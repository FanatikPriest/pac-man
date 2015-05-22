#include "application.h"
#include "window_settings.h"
#include "keyboard_handler.h"
#include "utilities\delta.h"

#include "controllers\game_controller.h"

#include "renderers\game_renderer.h"


Application::Application()
{
	_is_running     = true;
	_window         = NULL;
	_renderer       = NULL;
}

int Application::on_execute()
{
	if (initialize() == false)
	{
		return -1;
	}

	SDL_Event event;

	while (_is_running)
	{
		while (SDL_PollEvent(&event))
		{
			handle_events(event);
		}

		update();
		render();
	}

	cleanup();

	return 0;
}

bool Application::initialize()
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

void Application::handle_events(const SDL_Event& event)
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

void Application::update()
{
	Delta::set();

	GameController game_controller(_game);

	game_controller.update();
}

void Application::render()
{
	// fill with black to wipe previous frame
	SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(_renderer);

	GameRenderer game_renderer(_game, _renderer);

	game_renderer.render();

	// update the surface with this frame's graphics
	SDL_RenderPresent(_renderer);
}

void Application::cleanup()
{
	SDL_DestroyWindow(_window);

	SDL_Quit();
}
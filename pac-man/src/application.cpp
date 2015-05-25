#include <SDL_ttf.h>

#include "application.h"
#include "application_settings.h"
#include "keyboard_handler.h"

#include "controllers\game_controller.h"

#include "renderers\game_renderer.h"

#include "utilities\delta.h"
#include "utilities\fonts.h"


Application::Application()
{
	_is_running     = true;
	_window         = NULL;
	_renderer       = NULL;
}

int Application::execute()
{
	if (initialize() == false)
	{
		return -1;
	}

	SDL_Event event;

	while (_is_running)
	{
		Delta::set();

		while (SDL_PollEvent(&event))
		{
			handle_events(event);
		}

		update();
		render();

		// wait till the end of the time frame if needed
		Uint32 frame_ticks = SDL_GetTicks() - Delta::get_ticks();
		if (frame_ticks < ApplicationSettings::TICKS_PER_FRAME)
		{
			SDL_Delay(ApplicationSettings::TICKS_PER_FRAME - frame_ticks);
		}
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
								ApplicationSettings::WINDOW_WIDTH,
								ApplicationSettings::WINDOW_HEIGHT,
								SDL_WINDOW_SHOWN);

	if (_window == NULL)
	{
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (!Fonts::load_fonts())
	{
		return false;
	}

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
	Fonts::unload_fonts();

	SDL_DestroyRenderer(_renderer);

	SDL_DestroyWindow(_window);

	SDL_Quit();
}
#include "application.h"
#include "window_settings.h"
#include "keyboard_handler.h"

Application::Application()
{
	_is_running = true;
	_sdl_window = NULL;
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

	_sdl_window = SDL_CreateWindow("Pac-Man",
								   SDL_WINDOWPOS_CENTERED,
								   SDL_WINDOWPOS_CENTERED,
								   WindowSettings::WINDOW_WIDTH,
								   WindowSettings::WINDOW_HEIGHT,
								   SDL_WINDOW_SHOWN); // TODO: try SDL_WINDOW_FULLSCREEN_DESKTOP, would it achieve downscaling?

	if (_sdl_window == NULL)
	{
		return false;
	}

	return true;
}

void Application::on_event(const SDL_Event& event)
{
	switch (event.type) {
		case SDL_QUIT: {
			_is_running = false;
			break;
		}
		case SDL_KEYDOWN:
		case SDL_KEYUP: {
			KeyboardHandler& keyboard = KeyboardHandler::get_instance();

			switch (event.key.keysym.scancode) {
				case SDL_SCANCODE_UP: {
					keyboard.up = event.key.state;
					break;
				}
				case SDL_SCANCODE_DOWN: {
					keyboard.down = event.key.state;
					break;
				}
				case SDL_SCANCODE_LEFT: {
					keyboard.left = event.key.state;
					break;
				}
				case SDL_SCANCODE_RIGHT: {
					keyboard.right = event.key.state;
					break;
				}
				case SDL_SCANCODE_ESCAPE: {
					_is_running = false;
					break;
				}
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

}

void Application::on_cleanup()
{
	SDL_Quit();
}
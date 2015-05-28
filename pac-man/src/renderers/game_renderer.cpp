#include "game_renderer.h"
#include "player_renderer.h"
#include "level_renderer.h"

#include "../config/application_settings.h"
#include "../utilities/fonts.h"

GameRenderer::GameRenderer(const Game& game, SDL_Renderer* renderer)
: BaseRenderer(renderer), _game(game)
{}

void GameRenderer::render()
{
	switch (_game._game_state)
	{
		case (GameState::IN_PROGRESS):
		{
			 render_level();
			 break;
		}
		case (GameState::WIN):
		{
			render_win_message();
			break;
		}
		case (GameState::LOSE):
		{
			render_lose_message();
			break;
		}
	}
}

void GameRenderer::render_level()
{
	LevelRenderer level_renderer(_game._level, _renderer);
	level_renderer.render();
}

void GameRenderer::render_win_message()
{
	render_message("You win!");
}

void GameRenderer::render_lose_message()
{
	render_message("You lose!");
}

void GameRenderer::render_message(const char* message)
{
	SDL_Color yellow = { 0xFF, 0xFF, 0x00, 0xFF };

	SDL_Surface* text_surface = TTF_RenderText_Solid(Fonts::END_GAME_MESSAGE_FONT, message, yellow);
	SDL_Texture* texture      = SDL_CreateTextureFromSurface(_renderer, text_surface);

	int x = ApplicationSettings::WINDOW_WIDTH / 2 - text_surface->w / 2;
	int y = (int)(ApplicationSettings::WINDOW_HEIGHT / 2 - text_surface->h / 2);
	int w = text_surface->w;
	int h = text_surface->h;

	SDL_Rect text_rect = { x, y, w, h };

	SDL_RenderCopy(_renderer, texture, NULL, &text_rect);

	// free resources
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(text_surface);
}
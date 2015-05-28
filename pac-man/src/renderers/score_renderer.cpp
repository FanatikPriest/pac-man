#include <string>

#include "score_renderer.h"

#include "../config/application_settings.h"

#include "../utilities/fonts.h"

ScoreRenderer::ScoreRenderer(const Score& score, SDL_Renderer* renderer)
	: BaseRenderer(renderer), _score(score)
{}

void ScoreRenderer::render()
{
	SDL_Color white = { 0xFF, 0xFF, 0xFF, 0xFF };

	std::string score_message = std::to_string(_score.get());

	SDL_Surface* text_surface = TTF_RenderText_Solid(Fonts::SCORE_FONT, score_message.c_str(), white);
	SDL_Texture* texture      = SDL_CreateTextureFromSurface(_renderer, text_surface);
	SDL_Rect     text_rect    = text_box(text_surface);

	SDL_RenderCopy(_renderer, texture, NULL, &text_rect);

	// free resources
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(text_surface);
}

SDL_Rect ScoreRenderer::text_box(SDL_Surface* surface)
{
	int x      = ApplicationSettings::WINDOW_WIDTH / 2 - surface->w / 2;
	int y      = (int) (ApplicationSettings::WINDOW_HEIGHT - Fonts::SCORE_FONT_SIZE);
	int width  = surface->w;
	int height = surface->h;

	return SDL_Rect{ x, y, width, height };
}
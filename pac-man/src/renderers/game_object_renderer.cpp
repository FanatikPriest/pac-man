#include "game_object_renderer.h"
#include "../application_settings.h"

GameObjectRenderer::GameObjectRenderer(const GameObject& game_object, SDL_Renderer* renderer)
	: BaseRenderer(renderer), _game_object(game_object)
{}

void GameObjectRenderer::render()
{
	set_color();

	render_object();

	render_center_point();

	render_collision_box();
}

void GameObjectRenderer::render_object()
{
	SDL_RenderFillRect(_renderer, &_game_object.get_bounding_box());
}

void GameObjectRenderer::render_center_point()
{
	if (!ApplicationSettings::DISPLAY_CENTER_POINTS)
	{
		return;
	}

	SDL_SetRenderDrawColor(_renderer, 0xFF, 0x00, 0x00, 0xFF); // red

	Vector2f position = _game_object.get_position();

	int x = (int)position.getX();
	int y = (int)position.getY();

	SDL_Rect rect = { x, y, 1, 1 };

	SDL_RenderFillRect(_renderer, &rect);
}

void GameObjectRenderer::render_collision_box()
{
	if (!ApplicationSettings::DISPLAY_COLLISION_BOXES)
	{
		return;
	}

	SDL_Rect box = _game_object.get_bounding_box();

	SDL_SetRenderDrawColor(_renderer, 0x00, 0xFF, 0x00, 0xFF); // green

	SDL_RenderDrawRect(_renderer, &box);
}
#include "moving_object_renderer.h"

MovingObjectRenderer::MovingObjectRenderer(const MovingObject& moving_object, SDL_Renderer* renderer)
	: GameObjectRenderer(moving_object, renderer), _moving_object(moving_object)
{}

void MovingObjectRenderer::render_object()
{
	SDL_RenderCopyEx(_renderer, get_texture(), NULL, &get_texture_rect(), get_rotation_angle(), NULL, SDL_FLIP_NONE);
}

void MovingObjectRenderer::set_color()
{
	// nothing
}

SDL_Rect MovingObjectRenderer::get_texture_rect()
{
	Size     size      = _moving_object.get_size();
	Size     half_size = _moving_object.get_half_size();
	Vector2f position  = _moving_object.get_position();

	int x      = (int) (position.getX() - half_size.width);
	int y      = (int) (position.getY() - half_size.height);
	int width  = (int) size.width;
	int height = (int) size.height;

	return SDL_Rect{ x, y, width, height };
}

double MovingObjectRenderer::get_rotation_angle()
{
	return 0.0f;
}
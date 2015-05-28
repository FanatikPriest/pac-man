#pragma once

#include "game_object_renderer.h"
#include "../models/moving_object.h"

class MovingObjectRenderer : public GameObjectRenderer
{
public:
	MovingObjectRenderer(const MovingObject& moving_object, SDL_Renderer* renderer);

protected:
	virtual void render_object();

	virtual void             set_color();
	virtual SDL_Rect         get_texture_rect();
	virtual SDL_Texture*     get_texture() = 0;
	virtual double           get_rotation_angle();
	virtual SDL_RendererFlip get_flip();

private:
	const MovingObject& _moving_object;
};
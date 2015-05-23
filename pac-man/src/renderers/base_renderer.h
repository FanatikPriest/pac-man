#pragma once

#include <SDL.h>

class BaseRenderer
{
public:
	BaseRenderer(SDL_Renderer* renderer);

	virtual void render() = 0;

protected:
	SDL_Renderer* _renderer;

	virtual void set_color();
};

inline BaseRenderer::BaseRenderer(SDL_Renderer* renderer)
{
	_renderer = renderer;
}

inline void BaseRenderer::set_color() {}
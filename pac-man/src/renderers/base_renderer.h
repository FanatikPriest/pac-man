#pragma once

#include <SDL.h>

/*
A base class for all other renderers.
*/
class BaseRenderer
{
public:
	BaseRenderer(SDL_Renderer* renderer);

	virtual void render() = 0;

protected:
	SDL_Renderer* _renderer;
};

inline BaseRenderer::BaseRenderer(SDL_Renderer* renderer)
{
	_renderer = renderer;
}
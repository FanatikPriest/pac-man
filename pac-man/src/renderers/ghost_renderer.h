#pragma once

#include "moving_object_renderer.h"
#include "../models/ghost.h"

class GhostRenderer : public MovingObjectRenderer
{
public:
	GhostRenderer(const Ghost& ghost, SDL_Renderer* renderer);

protected:
	virtual SDL_Texture* get_texture();

private:
	const Ghost& _ghost;
};
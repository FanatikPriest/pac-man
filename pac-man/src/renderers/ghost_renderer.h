#pragma once

#include "game_object_renderer.h"
#include "../models/ghost.h"

class GhostRenderer : public GameObjectRenderer
{
public:
	GhostRenderer(const Ghost& ghost, SDL_Renderer* renderer);

protected:
	virtual void set_color();

private:
	const Ghost& _ghost;
};
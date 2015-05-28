#include "ghost_renderer.h"

#include "../utilities/directions.h"
#include "../utilities/textures.h"

GhostRenderer::GhostRenderer(const Ghost& ghost, SDL_Renderer* renderer)
	: MovingObjectRenderer(ghost, renderer), _ghost(ghost)
{}

SDL_Texture* GhostRenderer::get_texture()
{
	GhostMode mode = _ghost.get_mode();

	if (mode == GhostMode::FRIGHTENED)
	{
		return Textures::GHOST_FRIGHTENED_TEXTURE;
	}
	else if (mode == GhostMode::EATEN)
	{
		return Textures::GHOST_EATEN_TEXTURE;
	}

	return Textures::GHOST_TEXTURE;
}

SDL_RendererFlip GhostRenderer::get_flip()
{
	if (_ghost.get_direction() == Directions::LEFT)
	{
		return SDL_FLIP_HORIZONTAL;
	}

	return SDL_FLIP_NONE;
}
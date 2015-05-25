#include "ghost_renderer.h"

GhostRenderer::GhostRenderer(const Ghost& ghost, SDL_Renderer* renderer)
	: GameObjectRenderer(ghost, renderer), _ghost(ghost)
{}

void GhostRenderer::set_color()
{
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0x00, 0x00, 0xFF); // red
}
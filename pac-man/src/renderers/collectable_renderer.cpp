#include "collectable_renderer.h"

CollectableRenderer::CollectableRenderer(const Collectable& collectable, SDL_Renderer* renderer)
	: GameObjectRenderer(collectable, renderer), _collectable(collectable)
{}


void CollectableRenderer::set_color()
{
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xC0, 0xA0, 0xFF);
}

void CollectableRenderer::render_object()
{
	if (_collectable.is_collected())
	{
		return;
	}

	GameObjectRenderer::render_object();
}
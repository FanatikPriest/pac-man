#include "ghost_renderer.h"

#include "../config/game_settings.h"

GhostRenderer::GhostRenderer(const Ghost& ghost, SDL_Renderer* renderer)
	: GameObjectRenderer(ghost, renderer), _ghost(ghost)
{}

void GhostRenderer::set_color()
{
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0x00, 0x00, 0xFF); // red

	if (!GameSettings::DISPLAY_GHOST_STATE_MODE)
	{
		return;
	}

	switch (_ghost.get_mode())
	{
		case (GhostMode::SCATTER) :
		{
			SDL_SetRenderDrawColor(_renderer, 0x00, 0xFF, 0x00, 0xFF); // green
			break;
		}
		case (GhostMode::FRIGHTENED) :
		{
			SDL_SetRenderDrawColor(_renderer, 0x80, 0x80, 0xFF, 0xFF); // light blue
			break;
		}
	}
}

void GhostRenderer::render_object()
{
	if (_ghost.get_mode() == GhostMode::EATEN)
	{
		SDL_RenderDrawRect(_renderer, &_ghost.get_bounding_box());
	}
	else
	{
		GameObjectRenderer::render_object();
	}
}
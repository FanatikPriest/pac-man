#include "player_renderer.h"

PlayerRenderer::PlayerRenderer(const Player& player, SDL_Renderer* renderer)
	: GameObjectRenderer(player, renderer), _player(player)
{}

void PlayerRenderer::set_color()
{
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0x00, 0xFF); // yellow
}
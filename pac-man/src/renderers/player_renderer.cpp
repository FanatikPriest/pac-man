#include "player_renderer.h"
#include "score_renderer.h"

PlayerRenderer::PlayerRenderer(const Player& player, SDL_Renderer* renderer)
	: GameObjectRenderer(player, renderer), _player(player)
{}

void PlayerRenderer::render()
{
	GameObjectRenderer::render();

	render_score();
}

void PlayerRenderer::set_color()
{
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0x00, 0xFF); // yellow
}

void PlayerRenderer::render_score()
{
	ScoreRenderer(_player._score, _renderer).render();
}
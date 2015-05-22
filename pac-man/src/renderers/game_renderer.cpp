#include "game_renderer.h"
#include "player_renderer.h"

GameRenderer::GameRenderer(const Game& game, SDL_Renderer* renderer) : _game(game)
{
	_renderer = renderer;
}

void GameRenderer::render()
{
	PlayerRenderer player_renderer(_game._player, _renderer);
	player_renderer.render();
}
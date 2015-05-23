#include "game_renderer.h"
#include "player_renderer.h"
#include "level_renderer.h"

GameRenderer::GameRenderer(const Game& game, SDL_Renderer* renderer)
: BaseRenderer(renderer), _game(game)
{}

void GameRenderer::render()
{
	LevelRenderer level_renderer(_game._level, _renderer);
	level_renderer.render();

	PlayerRenderer player_renderer(_game._player, _renderer);
	player_renderer.render();
}
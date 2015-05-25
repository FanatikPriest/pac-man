#include "game.h"

Game::Game() : _game_state(GameState::IN_PROGRESS) {}

void Game::check_game_state()
{
	if (_game_state == GameState::IN_PROGRESS)
	{
		if (_level.get_collectables_count() == _level.get_collected_items_count())
		{
			_game_state = GameState::WIN;
		}
		else if (_level.has_ghost_collision_occured())
		{
			_game_state = GameState::LOSE;
		}
	}
}
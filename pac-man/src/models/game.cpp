#include "game.h"

#include "../controllers/level_controller.h"

Game::Game() : _game_state(GameState::IN_PROGRESS)
{
	LevelController(_level).create();
}

void Game::check_game_state()
{
	if (_game_state == GameState::IN_PROGRESS)
	{
		if (_level.get_map().get_collectables_count() == _level.get_collected_items_count())
		{
			_game_state = GameState::WIN;
		}
		else if (_level.is_player_dead())
		{
			_game_state = GameState::LOSE;
		}
	}
}
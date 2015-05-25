#include "game_controller.h"
#include "level_controller.h"

GameController::GameController(Game& game) : _game(game) {}

void GameController::update()
{
	_game.check_game_state();

	if (_game._game_state == GameState::IN_PROGRESS)
	{
		LevelController level_controller(_game._level);
		level_controller.update();
	}
}
#include "game_controller.h"
#include "level_controller.h"

GameController::GameController(Game& game) : _game(game) {}

void GameController::update()
{
	LevelController level_controller(_game._level);
	level_controller.update();
}
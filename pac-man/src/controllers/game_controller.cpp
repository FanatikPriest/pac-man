#include "game_controller.h"
#include "player_controller.h"

GameController::GameController(Game& game) : _game(game) {}

void GameController::update()
{
	PlayerController player_controller(_game._player);
	player_controller.update();
}
#include "player_controller.h"
#include "../movement_handler.h"

PlayerController::PlayerController(Player& player) : _player(player) {}

void PlayerController::update()
{
	MovementHandler::move_player(_player);
}
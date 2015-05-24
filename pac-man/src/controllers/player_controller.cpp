#include "player_controller.h"
#include "../movement_handler.h"

PlayerController::PlayerController(Player& player) : _player(player) {}

void PlayerController::update()
{
	MovementHandler::move_player(_player);
}

void PlayerController::handle_movement_collision(const GameObject& game_object)
{
	SDL_Rect intersection;

	SDL_IntersectRect(&_player.get_bounding_box(), &game_object.get_bounding_box(), &intersection);

	Vector2f reversed_direction = _player.get_direction() * -1.0f;

	Vector2f offset(intersection.w * reversed_direction.getX(), intersection.h * reversed_direction.getY());

	_player.set_position(_player.get_position() + offset);
}
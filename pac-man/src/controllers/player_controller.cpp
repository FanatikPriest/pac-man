#include "player_controller.h"
#include "../movement_handler.h"

PlayerController::PlayerController(Player& player) : _player(player) {}

void PlayerController::update()
{
	MovementHandler::move_player(_player);
}

void PlayerController::handle_movement_collision(const GameObject& game_object)
{
	// TODO this could be optimized

	Vector2f player_position  = _player.get_position();
	Vector2f player_direction = _player.get_direction();

	Vector2f distance_to_object = game_object.get_position() - player_position;
	Vector2f abs_direction(player_direction.getX() * player_direction.getX(), player_direction.getY() * player_direction.getY());
	Vector2f backward_distance_correction(distance_to_object.getX() * abs_direction.getX(), distance_to_object.getY() * abs_direction.getY());

	Vector2f reversed_direction = player_direction * -1.0f;

	Size half_size_sum = _player.get_half_size() + game_object.get_half_size();

	Vector2f supposed_position_offset(half_size_sum.width * reversed_direction.getX(), half_size_sum.height * reversed_direction.getY());

	Vector2f new_position = player_position + backward_distance_correction + supposed_position_offset;

	_player.set_position(new_position);
}
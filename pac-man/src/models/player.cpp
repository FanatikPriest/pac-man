#include "player.h"

Player::Player() : MovingObject()
{
	set_is_alive(true);
}

Player::Player(Vector2f position, Size size, Vector2f direction, float speed)
	: MovingObject(position, size, true, direction, speed)
{
	set_is_alive(true);
}
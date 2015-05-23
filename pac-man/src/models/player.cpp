#include "player.h"

Player::Player() : MovingObject() {}

Player::Player(Vector2f position, Size size, Vector2f direction, float speed)
	: MovingObject(position, size, direction, speed, true)
{}
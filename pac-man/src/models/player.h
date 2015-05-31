#pragma once

#include "moving_object.h"
#include "score.h"

/*
Pac-man. Keeps the score and can be alive or dead.
*/
class Player : public MovingObject
{
public:
	Player();
	Player(Vector2f position, Size size, Vector2f direction, float speed);

	void set_is_alive(bool is_alive);
	bool is_alive() const;

	Score& get_score();

private:
	Score _score;
	bool  _is_alive;
};

inline void Player::set_is_alive(bool is_alive)
{
	_is_alive = is_alive;
}

inline bool Player::is_alive() const
{
	return _is_alive;
}

inline Score& Player::get_score()
{
	return _score;
}
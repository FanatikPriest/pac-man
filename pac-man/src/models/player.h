#pragma once

#include "moving_object.h"
#include "score.h"

class Player : public MovingObject
{
public:
	Player();
	Player(Vector2f position, Size size, Vector2f direction, float speed);

	void set_is_alive(bool is_alive);
	bool is_alive() const;

private:
	Score _score;
	bool  _is_alive;

	friend class PlayerController;
	friend class PlayerRenderer;
};

inline void Player::set_is_alive(bool is_alive)
{
	_is_alive = is_alive;
}

inline bool Player::is_alive() const
{
	return _is_alive;
}
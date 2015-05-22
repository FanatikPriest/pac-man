#include "game.h"

Game::Game()
{
	create_player(100.0f, 100.0f);
}

void Game::create_player(float x = 0.0f, float y = 0.0f)
{
	Vector2f position(x, y);
	Size     size(50, 50);
	Vector2f direction(0.0f, 0.0f);
	float    speed = 6.0f;

	_player = Player(position, size, direction, speed);
}
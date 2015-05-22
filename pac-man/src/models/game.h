#pragma once

#include "player.h"

class Game
{
public:
	Game();

private:
	Player _player;

	void create_player(float x, float y);

	friend class GameController;
	friend class GameRenderer;
};
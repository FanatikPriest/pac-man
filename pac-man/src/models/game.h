#pragma once

#include "player.h"
#include "level.h"

class Game
{
public:
	Game();

private:
	Player _player;
	Level  _level;

	void create_player(float x, float y);

	friend class GameController;
	friend class GameRenderer;
};
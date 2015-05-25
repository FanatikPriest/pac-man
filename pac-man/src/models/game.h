#pragma once

#include "player.h"
#include "level.h"
#include "game_state.h"

class Game
{
public:
	Game();

	void check_game_state();

private:
	Level     _level;
	GameState _game_state;

	friend class GameController;
	friend class GameRenderer;
};
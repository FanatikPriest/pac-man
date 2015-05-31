#pragma once

#include "player.h"
#include "level.h"
#include "../enums/game_state.h"

/*
The game contains the level and the current game state.
*/
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
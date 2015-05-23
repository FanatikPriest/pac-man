#pragma once

#include "player.h"
#include "level.h"

class Game
{
private:
	Level  _level;

	friend class GameController;
	friend class GameRenderer;
};
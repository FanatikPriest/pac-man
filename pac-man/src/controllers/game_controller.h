#pragma once

#include "../models/game.h"

class GameController
{
public:
	GameController(Game& game);

	void update();

private:
	Game& _game;
};
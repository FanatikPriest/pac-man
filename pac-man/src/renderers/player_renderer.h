#pragma once

#include "game_object_renderer.h"
#include "../models/player.h"

class PlayerRenderer : public GameObjectRenderer
{
public:
	PlayerRenderer(const Player& player, SDL_Renderer* renderer);

protected:
	virtual void set_color();

private:
	const Player& _player;
};
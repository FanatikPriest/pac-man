#pragma once

#include "moving_object_renderer.h"
#include "../models/player.h"

/*
Renders the player and delegates the rendering of the score.
*/
class PlayerRenderer : public MovingObjectRenderer
{
public:
	PlayerRenderer(const Player& player, SDL_Renderer* renderer);

	virtual void render();

protected:
	virtual SDL_Texture* get_texture();
	virtual double       get_rotation_angle();

private:
	const Player& _player;

	void render_score();
};
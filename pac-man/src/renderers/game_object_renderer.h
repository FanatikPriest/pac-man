#pragma once

#include "base_renderer.h"
#include "../models/game_object.h"

class GameObjectRenderer : public BaseRenderer
{
public:
	GameObjectRenderer(const GameObject& game_object, SDL_Renderer* renderer);

	virtual void render();

protected:
	virtual void set_color() = 0;
	virtual void render_object();

private:
	const GameObject& _game_object;

	void render_center_point();
	void render_collision_box();
};
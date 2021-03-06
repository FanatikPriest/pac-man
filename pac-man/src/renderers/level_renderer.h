#pragma once

#include "base_renderer.h"
#include "../models/level.h"

/*
Delegates the rendering of all game objects.
*/
class LevelRenderer : public BaseRenderer
{
public:
	LevelRenderer(const Level& level, SDL_Renderer* renderer);

	virtual void render();

private:
	const Level& _level;

	void render_tiles();
	void render_pac_dots();
	void render_power_ups();
	void render_ghosts();
	void render_player();
};
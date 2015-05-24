#pragma once

#include "game_object_renderer.h"
#include "../models/collectable.h"

class CollectableRenderer : public GameObjectRenderer
{
public:
	CollectableRenderer(const Collectable& collectable, SDL_Renderer* renderer);

protected:
	virtual void set_color();
	virtual void render_object();

private:
	const Collectable& _collectable;
};
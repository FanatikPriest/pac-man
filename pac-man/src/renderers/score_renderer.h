#pragma once

#include "base_renderer.h"
#include "../models/score.h"

class ScoreRenderer : public BaseRenderer
{
public:
	ScoreRenderer(const Score& score, SDL_Renderer* renderer);

	virtual void render();

private:
	const Score& _score;

	SDL_Rect text_box(SDL_Surface* surface);
};
#pragma once

#include <SDL_ttf.h>

class Fonts
{
public:
	static bool load_fonts();
	static void unload_fonts();

	static TTF_Font* SCORE_FONT;
	static int SCORE_FONT_SIZE;
};
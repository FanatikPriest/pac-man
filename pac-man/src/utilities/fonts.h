#pragma once

#include <SDL_ttf.h>

/*
Manages the fonts used in the game.
*/
class Fonts
{
public:
	static bool load_fonts();
	static void unload_fonts();

	static TTF_Font* SCORE_FONT;
	static TTF_Font* END_GAME_MESSAGE_FONT;

	static int SCORE_FONT_SIZE;
	static int END_GAME_MESSAGE_FONT_SIZE;
};
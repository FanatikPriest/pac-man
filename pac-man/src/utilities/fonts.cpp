#include "fonts.h"

bool Fonts::load_fonts()
{
	if (TTF_Init() == -1)
	{
		return false;
	}

	SCORE_FONT = TTF_OpenFont("data/Munro.ttf", SCORE_FONT_SIZE);

	return SCORE_FONT != NULL;
}

void Fonts::unload_fonts()
{
	TTF_CloseFont(SCORE_FONT);

	TTF_Quit();
}

int Fonts::SCORE_FONT_SIZE  = 48;

TTF_Font* Fonts::SCORE_FONT = NULL;
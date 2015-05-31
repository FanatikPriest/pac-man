#include "delta.h"
#include "../config/application_settings.h"

Uint32 Delta::_last  = SDL_GetTicks();
float  Delta::_delta = 0.0f;

float Delta::get()
{
	return _delta;
}

/*
Calculates the time last frame took.
*/
void Delta::set()
{
	Uint32 now = SDL_GetTicks();

	_delta = (now - _last) / (float) ApplicationSettings::FRAMES_PER_SECOND_CAP;
	_last = now;
}

/*
Returns the milliseconds (ticks) from the start of the game.
*/
Uint32 Delta::get_ticks()
{
	return _last;
}
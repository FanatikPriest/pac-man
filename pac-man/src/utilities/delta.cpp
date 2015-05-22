#include "delta.h"
#include "../application_settings.h"

Uint32 Delta::_last = SDL_GetTicks();
float Delta::_delta = 0.0f;

float Delta::get()
{
	return _delta;
}

void Delta::set()
{
	Uint32 now = SDL_GetTicks();

	_delta = (now - _last) / (float) ApplicationSettings::FRAMES_PER_SECOND_CAP;
	_last = now;
}

Uint32 Delta::get_ticks()
{
	return _last;
}
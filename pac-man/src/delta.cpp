#include "delta.h"

Uint32 Delta::_last = SDL_GetTicks();
float Delta::_delta = 0.0f;

float Delta::get()
{
	return _delta;
}

void Delta::set()
{
	Uint32 now = SDL_GetTicks();

	_delta = (now - _last) / 25.0f;
	_last = now;
}
#pragma once

#include <SDL.h>

/*
Measures the elapsed time and the time each frame takes.
*/
class Delta
{
public:
	static float  get();
	static void   set();
	static Uint32 get_ticks();

private:
	static Uint32 _last;
	static float  _delta;

	Delta();
	Delta(const Delta&);
	Delta& operator=(const Delta&);
};
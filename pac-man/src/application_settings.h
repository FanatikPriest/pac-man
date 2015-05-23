#pragma once

namespace ApplicationSettings
{
	static const int WINDOW_WIDTH  = 1024;
	static const int WINDOW_HEIGHT = 768;

	static const int FRAMES_PER_SECOND_CAP = 60;
	static const int TICKS_PER_FRAME       = 1000 / FRAMES_PER_SECOND_CAP;

	// Debugging
	static const bool DISPLAY_CENTER_POINTS   = false;
	static const bool DISPLAY_COLLISION_BOXES = false;
}
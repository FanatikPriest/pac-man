#pragma once

namespace ApplicationSettings
{
	static const int WINDOW_WIDTH  = 560;
	static const int WINDOW_HEIGHT = 660;

	static const int FRAMES_PER_SECOND_CAP = 60;
	static const int TICKS_PER_FRAME       = 1000 / FRAMES_PER_SECOND_CAP;

	// Game settings:
	static const float GAME_OBJECT_SIZE = 20.0f;
	static const float PLAYER_SPEED     = 10.0f;
	static const float GHOST_SPEED      = 7.0f;
	static const float PAC_DOT_SIZE     = 6.0f;
	static const float POWER_UP_SIZE    = 12.0f;
	static const int   SCATTER_MODE_DURATION = 10000; // 10 seconds
	static const int   CHASE_MODE_DURATION   = 20000; // 20 seconds

	// Debugging
	static const bool DISPLAY_CENTER_POINTS   = false;
	static const bool DISPLAY_COLLISION_BOXES = false;
}
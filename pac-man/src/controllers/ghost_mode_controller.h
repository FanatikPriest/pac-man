#pragma once

#include "../utilities/delta.h"
#include "../config/game_settings.h"
#include "../models/ghost_mode.h"

class GhostModeController
{
public:
	static void      update();
	static GhostMode get_current_mode();
	static void      set_current_mode(GhostMode mode);

private:
	static int       LAST_CHANGE_TICKS;
	static GhostMode CURRENT_MODE;

	static void change_mode();
	static int current_mode_duration();
};

inline void GhostModeController::update()
{
	int duration = current_mode_duration();

	if (((int)Delta::get_ticks() - LAST_CHANGE_TICKS) >= duration)
	{
		change_mode();
	}
}

inline void GhostModeController::change_mode()
{
	if (CURRENT_MODE == GhostMode::SCATTER || CURRENT_MODE == GhostMode::FRIGHTENED)
	{
		set_current_mode(GhostMode::CHASE);
	}
	else
	{
		set_current_mode(GhostMode::SCATTER);
	}
}

inline int GhostModeController::current_mode_duration()
{
	if (CURRENT_MODE == GhostMode::CHASE)
	{
		return GameSettings::CHASE_MODE_DURATION;
	}
	else if (CURRENT_MODE == GhostMode::FRIGHTENED)
	{
		return GameSettings::FRIGHTENED_MODE_DURATION;
	}
	
	return GameSettings::SCATTER_MODE_DURATION;
}

inline GhostMode GhostModeController::get_current_mode()
{
	return CURRENT_MODE;
}

inline void GhostModeController::set_current_mode(GhostMode mode)
{
	CURRENT_MODE = mode;

	LAST_CHANGE_TICKS = (int)Delta::get_ticks();
}
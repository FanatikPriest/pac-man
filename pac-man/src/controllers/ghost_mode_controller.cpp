#include "ghost_mode_controller.h"

int       GhostModeController::LAST_CHANGE_TICKS = 0;
GhostMode GhostModeController::CURRENT_MODE      = GhostMode::SCATTER;
#include "ghost_controller.h"

GhostController::GhostController(Ghost& ghost, Tile* underlying_tile)
	: MovingObjectController(ghost, underlying_tile), _ghost(ghost)
{}

void GhostController::move_object()
{
	MovingObjectController::move_object();
}

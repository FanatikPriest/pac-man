#include "ghost_controller.h"
#include "ghost_mode_controller.h"

#include "../config/game_settings.h"
#include "../utilities/directions.h"

GhostController::GhostController(Ghost& ghost, const Level& level, Tile* underlying_tile)
	: MovingObjectController(ghost, underlying_tile), _ghost(ghost), _level(level)
{}

void GhostController::update()
{
	set_mode();

	set_target();

	MovingObjectController::update();
}

/*
If the ghost is in the 'eaten' mode and is not at its ultimate destination (center of the maze) do nothing.
Otherwise set the current mode set in the GhostModeController.
*/
void GhostController::set_mode()
{
	if (_ghost.get_mode() == GhostMode::EATEN)
	{
		bool is_at_ultimate_target = (_underlying_tile->get_position() == determine_ultimate_target());
		
		if (!is_at_ultimate_target)
		{
			return;
		}
	}

	_ghost.set_mode(GhostModeController::get_current_mode());
}

/*
If the current target tile position is reached, the adjecent tile position closest to
the ultimate target is set as a new target.
*/
void GhostController::set_target()
{
	float distance_to_target = (_ghost.get_position() - _ghost.get_target()).getMagnitude();

	// when the ghost is not near the center of the target, we don't change anything
	if (!(_ghost.get_target() == Vector2f(0.0f, 0.0f)) && distance_to_target > GameSettings::GAME_OBJECT_SIZE / 5.0f)
	{
		return;
	}

	Vector2f next_target = determine_next_target();

	if (!(next_target == Vector2f(0.0f, 0.0f)))
	{
		_ghost.set_target(next_target);
		_ghost.set_position(_underlying_tile->get_position()); // center ghost on underlying tile

		change_ghost_direction(); // towards the new target
	}
}

/*
Determines the adjecent tile that is the closest to the ultimate target (e.g. the player)
and returns its position.
*/
Vector2f GhostController::determine_next_target() const
{
	Vector2f* adjecent_tile_positions  = get_adjecent_tile_positions();
	Vector2f  ultimate_target_position = determine_ultimate_target();

	Vector2f nearest_to_ultimate_target;

	float magnitude = 10000000.0f;

	for (int iter = 0; iter < 3; iter++)
	{
		Vector2f adjecent_tile = adjecent_tile_positions[iter];

		if (adjecent_tile == Vector2f(0.0f, 0.0f))
		{
			continue;
		}

		float distance_to_ultimate_target = (adjecent_tile - ultimate_target_position).getMagnitude();

		if (distance_to_ultimate_target < magnitude)
		{
			magnitude = distance_to_ultimate_target;
			nearest_to_ultimate_target = adjecent_tile;
		}
	}

	delete[] adjecent_tile_positions;

	return nearest_to_ultimate_target;
}

/*
Returns the positions of tiles that are ahead or to the side of the
underlying tile by checking the ghost's direction. Returning only 
these three tiles will guarantee no moving in reverse direction.

At the start of the game the ghost should not move down - it will
mimic the movement in upwards direction.
*/
Vector2f* GhostController::get_adjecent_tile_positions() const
{
	int i = _underlying_tile->get_row();
	int j = _underlying_tile->get_column();

	Vector2f ghost_direction = _ghost.get_direction();

	Vector2f* adjecent_tiles = new Vector2f[3];

	if (ghost_direction == Directions::UP || ghost_direction == Vector2f(0.0f, 0.0f))
	{
		adjecent_tiles[0] = get_tile_position_at(i - 1, j);
		adjecent_tiles[1] = get_tile_position_at(i, j - 1);
		adjecent_tiles[2] = get_tile_position_at(i, j + 1);

	}
	else if (ghost_direction == Directions::DOWN)
	{
		adjecent_tiles[0] = get_tile_position_at(i, j - 1);
		adjecent_tiles[1] = get_tile_position_at(i, j + 1);
		adjecent_tiles[2] = get_tile_position_at(i + 1, j);
	}
	else if (ghost_direction == Directions::LEFT)
	{
		adjecent_tiles[0] = get_tile_position_at(i - 1, j);
		adjecent_tiles[1] = get_tile_position_at(i, j - 1);
		adjecent_tiles[2] = get_tile_position_at(i + 1, j);
	}
	else if (ghost_direction == Directions::RIGHT)
	{
		adjecent_tiles[0] = get_tile_position_at(i - 1, j);
		adjecent_tiles[1] = get_tile_position_at(i, j + 1);
		adjecent_tiles[2] = get_tile_position_at(i + 1, j);
	}

	return adjecent_tiles;
}

/*
Depending on the current ghost mode the ultimate target can be the player,
one of the map corners (retreat tiles) or the ghost's starting position.
*/
Vector2f GhostController::determine_ultimate_target() const
{
	switch (_ghost.get_mode())
	{
		case (GhostMode::CHASE) :
		{
			return _level.get_player().get_position();
		}
		case (GhostMode::SCATTER) :
		case (GhostMode::FRIGHTENED) :
		{
			return _level.get_retreat_tile_position(_ghost.get_index());
		}
		case (GhostMode::EATEN) :
		{
			return _level.get_ghost_initial_tile_position(_ghost.get_index());
		}
	}

	return Vector2f();
}

/*
Changes the direction of the ghost so it can move towards its target.
*/
void GhostController::change_ghost_direction()
{
	const Tile* target_tile = _level.get_tile_at(_ghost.get_target());

	float dx = (float) (target_tile->get_column() - _underlying_tile->get_column());
	float dy = (float) (target_tile->get_row() - _underlying_tile->get_row());

	Vector2f next_direction(dx, dy);

	if (next_direction.getMagnitude() == 1.0f)
	{
		set_direction(next_direction);
	}
	else
	{
		set_direction(Vector2f(0.0f, 0.0f));
	}
}

/*
x and y are zero-based tile indices.
*/
Vector2f GhostController::get_tile_position_at(int x, int y) const
{
	Tile* tile = _level.get_tile_at(x, y);

	return tile->is_rigid() ? Vector2f(0.0f, 0.0f) : tile->get_position();
}
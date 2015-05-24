#include "level_controller.h"
#include "../utilities/collision_detector.h"

LevelController::LevelController(Level& level) : _level(level) {}

void LevelController::update()
{
	Tile* underlying_tile = _level.get_tile_at(_level._player.get_position());

	PlayerController player_controller(_level._player, underlying_tile);
	player_controller.update();

	handle_tile_collisions(player_controller);
}

void LevelController::handle_tile_collisions(PlayerController& player_controller)
{
	int count = _level.get_tiles_count();

	Tile** tiles = _level.get_tiles();

	GameObject** objects = new GameObject*[count];

	for (int i = 0; i < count; i++)
	{
		objects[i] = dynamic_cast<GameObject*>(tiles[i]);
	}

	const GameObject* collision = CollisionDetector::collides_with(_level._player, objects, count);

	if (collision != NULL)
	{
		player_controller.handle_movement_collision(*collision);
	}
}
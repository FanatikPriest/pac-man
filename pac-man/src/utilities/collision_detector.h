#pragma once

#include <SDL.h>

#include "../models/game_object.h"

/*
Detects collisions between an object (target) and a group of objects.
*/
namespace CollisionDetector
{
	const GameObject* collides_with(const GameObject& target, GameObject** objects, const int objects_size);
	bool has_collision(const GameObject& a, const GameObject& b);
}
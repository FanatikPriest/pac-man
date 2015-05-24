#pragma once

#include <SDL.h>

#include "../models/game_object.h"

namespace CollisionDetector
{
	/*
	* Returns a pointer to the first game object that the target object collides with.
	*/
	const GameObject* collides_with(const GameObject& target, GameObject** objects, const int objects_size);
	bool has_collision(const GameObject& a, const GameObject& b);
}



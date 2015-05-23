#pragma once

#include <SDL.h>

#include "../models/game_object.h"

namespace CollisionDetector
{
	/*
	* Checks whether two rectangles collide or not.
	*/
	bool check_collision(const SDL_Rect& a, const SDL_Rect& b);

	/*
	* Returns a pointer to the first game object that the target object collides with.
	*/
	const GameObject* collides_with(const GameObject& target, GameObject** objects, const int objects_size);
}



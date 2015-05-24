#include "collision_detector.h"

const GameObject* CollisionDetector::collides_with(const GameObject& target, GameObject** objects, const int objects_size)
{
	const GameObject* result = NULL;

	for (int i = 0; i < objects_size; i++)
	{
		const GameObject* object = objects[i];

		if (has_collision(target, *object))
		{
			result = object;

			break;
		}
	}

	return result;
}

bool CollisionDetector::has_collision(const GameObject& a, const GameObject& b)
{
	if (!a.is_rigid() || !b.is_rigid())
	{
		return false;
	}

	SDL_Rect* a_box = &a.get_bounding_box();
	SDL_Rect* b_box = &b.get_bounding_box();

	return SDL_HasIntersection(a_box, b_box);
}
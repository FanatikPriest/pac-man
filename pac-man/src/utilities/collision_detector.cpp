#include "collision_detector.h"

const GameObject* CollisionDetector::collides_with(const GameObject& target, GameObject** objects, const int objects_size)
{
	SDL_Rect* a = &target.get_bounding_box();

	const GameObject* result = NULL;

	for (int i = 0; i < objects_size; i++)
	{
		const GameObject* object = objects[i];

		if (!object->is_rigid())
		{
			continue;
		}

		SDL_Rect* b = &object->get_bounding_box();

		if (SDL_HasIntersection(a, b))
		{
			result = object;

			break;
		}
	}

	return result;
}
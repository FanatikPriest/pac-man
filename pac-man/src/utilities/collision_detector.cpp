#include "collision_detector.h"

bool CollisionDetector::check_collision(const SDL_Rect& a, const SDL_Rect& b)
{
	// Calculate the sides of rect 'a'
	int left_a   = a.x;
	int right_a  = a.x + a.w;
	int top_a    = a.y;
	int bottom_a = a.y + a.h;

	// Calculate the sides of rect 'b'
	int left_b   = b.x;
	int right_b  = b.x + b.w;
	int top_b    = b.y;
	int bottom_b = b.y + b.h;

	// If any of the sides from 'a' are outside of 'b'
	if ((bottom_a <= top_b) || (top_a >= bottom_b) || (right_a <= left_b) || (left_a >= right_b))
	{
		return false;
	}

	// If none of the sides from 'a' are outside 'b'
	return true;
}

const GameObject* CollisionDetector::collides_with(const GameObject& target, GameObject** objects, const int objects_size)
{
	SDL_Rect& a = target.get_bounding_box();

	const GameObject* result = NULL;

	for (int i = 0; i < objects_size; i++)
	{
		const GameObject* object = objects[i];

		if (!object->is_rigid())
		{
			continue;
		}

		SDL_Rect& b = object->get_bounding_box();

		if (check_collision(a, b))
		{
			result = object;

			break;
		}
	}

	return result;
}
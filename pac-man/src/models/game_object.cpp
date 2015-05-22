#include "game_object.h"

GameObject::GameObject()
{
	float zero = 0.0f;

	set_position(zero, zero);
	set_size(zero, zero);
}

GameObject::GameObject(Vector2f position, Size size)
{
	set_position(position);
	set_size(size);
}

GameObject::GameObject(float x, float y, float height, float width)
{
	set_position(x, y);
	set_size(height, width);
}


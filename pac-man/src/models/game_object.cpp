#include "game_object.h"

GameObject::GameObject()
{
	float zero = 0.0f;

	set_position(zero, zero);
	set_size(zero, zero);
}

GameObject::GameObject(Vector2f position, Size size, bool is_rigid)
{
	set_position(position);
	set_size(size);
	set_is_rigid(is_rigid);
}

GameObject::GameObject(float x, float y, float height, float width, bool is_rigid)
{
	set_position(x, y);
	set_size(height, width);
	set_is_rigid(is_rigid);
}
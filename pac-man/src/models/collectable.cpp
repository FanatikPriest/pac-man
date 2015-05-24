#include "collectable.h"

Collectable::Collectable() : GameObject()
{
	set_collected(false);
}

Collectable::Collectable(Vector2f position, Size size, bool is_rigid) : GameObject(position, size, is_rigid)
{
	set_collected(false);
}

Collectable::Collectable(float x, float y, float height, float width, bool is_rigid) : GameObject(x, y, height, width, is_rigid)
{
	set_collected(false);
}
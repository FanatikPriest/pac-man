#include "power_up.h"

PowerUp::PowerUp() : Collectable() {}

PowerUp::PowerUp(Vector2f position, Size size) : Collectable(position, size, true) {}

PowerUp::PowerUp(float x, float y, float height, float width) : Collectable(x, y, height, width, true) {}
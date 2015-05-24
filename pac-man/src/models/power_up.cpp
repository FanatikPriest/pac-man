#include "power_up.h"

PowerUp::PowerUp() : Collectable() {}

PowerUp::PowerUp(Vector2f position, Size size) : Collectable(position, size, true) {}
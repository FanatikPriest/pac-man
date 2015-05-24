#include "pac_dot.h"

PacDot::PacDot() : Collectable() {}

PacDot::PacDot(Vector2f position, Size size) : Collectable(position, size, true) {}

PacDot::PacDot(float x, float y, float height, float width) : Collectable(x, y, height, width,true) {}
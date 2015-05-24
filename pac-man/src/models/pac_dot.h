#pragma once

#include "collectable.h"

class PacDot : public Collectable
{
public:
	PacDot();
	PacDot(Vector2f position, Size size);
	PacDot(float x, float y, float height, float width);
};
#pragma once

#include "collectable.h"

class PowerUp : public Collectable
{
public:
	PowerUp();
	PowerUp(Vector2f position, Size size);
};
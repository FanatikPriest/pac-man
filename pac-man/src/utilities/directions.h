#pragma once

#include "../math/vector_2f.h"

/*
Four normalized vectors the define the four movement directions.
*/
namespace Directions
{
	const float ZERO = 0.0f;
	const float ONE  = 1.0f;

	const Vector2f UP    = Vector2f(ZERO, -ONE);
	const Vector2f DOWN  = Vector2f(ZERO, ONE);
	const Vector2f LEFT  = Vector2f(-ONE, ZERO);
	const Vector2f RIGHT = Vector2f(ONE,  ZERO);
}
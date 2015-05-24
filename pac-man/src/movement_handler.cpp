#include "movement_handler.h"

const float MovementHandler::zero = 0.0f;
const float MovementHandler::one  = 1.0f;

const Vector2f MovementHandler::up    = Vector2f(zero, -one);
const Vector2f MovementHandler::down  = Vector2f(zero, one);
const Vector2f MovementHandler::left  = Vector2f(-one, zero);
const Vector2f MovementHandler::right = Vector2f(one,  zero);
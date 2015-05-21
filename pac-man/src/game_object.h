#pragma once

#include "vector_2f.h"
#include "size.h"

/*
* An object that has two-dimensional size (height and width) and a two-dimensional position.
*/
class GameObject
{
public:
	GameObject();
	GameObject(Vector2f position, Size size);
	GameObject(float x, float y, float height, float width);

	Size     get_size() const;
	void     set_size(Size size);
	void     set_size(float height, float width);
	Vector2f get_position() const;
	void     set_position(Vector2f position);
	void     set_position(float height, float width);

private:
	Vector2f _position;
	Size     _size;
};

// Inline function definitions:

inline Size GameObject::get_size() const
{
	return _size;
}

inline void GameObject::set_size(Size size)
{
	_size = size;
}

inline void GameObject::set_size(float height, float width)
{
	_size = Size(height, width);
}

inline Vector2f GameObject::get_position() const
{
	return _position;
}

inline void GameObject::set_position(Vector2f position)
{
	_position = position;
}

inline void GameObject::set_position(float x, float y)
{
	_position = Vector2f(x, y);
}
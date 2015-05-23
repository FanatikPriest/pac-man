#pragma once

#include <SDL.h>

#include "../vector_2f.h"
#include "../size.h"

/*
* An object that has two-dimensional size (height and width) and a two-dimensional position.
*/
class GameObject
{
public:
	GameObject();
	GameObject(Vector2f position, Size size, bool is_rigid);
	GameObject(float x, float y, float height, float width, bool is_rigid);

	Size     get_size() const;
	void     set_size(Size size);
	void     set_size(float height, float width);
	Vector2f get_position() const;
	void     set_position(Vector2f position);
	void     set_position(float height, float width);
	void     set_is_rigid(bool is_rigid);
	bool     is_rigid() const;

	SDL_Rect get_bounding_box() const;

private:
	Vector2f _position;
	Size     _size;
	Size     _half_size;
	bool     _is_rigid;
};

// Inline function definitions:

inline Size GameObject::get_size() const
{
	return _size;
}

inline void GameObject::set_size(Size size)
{
	_size = size;

	_half_size = Size(_size.height / 2.0f, _size.width / 2.0f);
}

inline void GameObject::set_size(float height, float width)
{
	set_size(Size(height, width));
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

inline void GameObject::set_is_rigid(bool is_rigid)
{
	_is_rigid = is_rigid;
}

inline bool GameObject::is_rigid() const
{
	return _is_rigid;
}

inline SDL_Rect GameObject::get_bounding_box() const
{
	int x = (int)(_position.getX() - _half_size.width);
	int y = (int)(_position.getY() - _half_size.height);

	return SDL_Rect { x, y, (int)_size.width, (int)_size.height };
}
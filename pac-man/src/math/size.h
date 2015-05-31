#pragma once

/*
A two-dimensional size of an object.
*/
struct Size
{
	float height;
	float width;

	Size()
	{
		height = 0.0f;
		width  = 0.0f;
	}

	Size(float dimension)
	{
		height = dimension;
		width  = dimension;
	}

	Size(float height, float width)
	{
		this->height = height;
		this->width  = width;
	}

	friend Size operator+(const Size& lhs, const Size& rhs)
	{
		return Size(lhs.height + rhs.height, lhs.width + rhs.width);
	}
};
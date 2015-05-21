#pragma once

struct Size
{
	float height;
	float width;

	Size()
	{
		height = 0.0f;
		width  = 0.0f;
	}

	Size(float height, float width)
	{
		this->height = height;
		this->width  = width;
	}
};
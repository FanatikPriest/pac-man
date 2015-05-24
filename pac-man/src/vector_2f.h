#pragma once

#include <math.h>
#include <iostream>

class Vector2f
{
public:
	Vector2f(float x = 0.0f, float y = 0.0f) : _x(x), _y(y) {}

	inline float getMagnitude() const
	{
		return sqrtf(_x * _x + _y * _y);
	}

	inline void normalize()
	{
		float magnitude = getMagnitude();

		if (magnitude == 0.0f)
		{
			return;
		}

		_x /= magnitude;
		_y /= magnitude;
	}

	inline void setX(float x) { _x = x; }
	inline void setY(float y) { _y = y; }

	inline void setCoordinates(float x, float y) { _x = x; _y = y; }

	inline float getX() const { return _x; }
	inline float getY() const { return _y; }

	inline Vector2f clone() const
	{
		return Vector2f(_x, _y);
	}

	inline Vector2f perp() const
	{
		return Vector2f(-_y, _x);
	}

	inline Vector2f rotate(const float &radians) const
	{
		return (*this) * cos(radians) + perp() * sin(radians);
	}

	inline bool operator==(const Vector2f & rhs) const
	{
		return _x == rhs._x && _y == rhs._y;
	}

	friend Vector2f operator+(const Vector2f & lhs, const Vector2f & rhs)
	{
		return Vector2f(lhs._x + rhs._x, lhs._y + rhs._y);
	}

	friend Vector2f operator-(const Vector2f & lhs, const Vector2f & rhs)
	{
		return Vector2f(lhs._x - rhs._x, lhs._y - rhs._y);
	}

	friend float operator*(const Vector2f & lhs, const Vector2f & rhs)
	{
		return lhs._x * rhs._x + lhs._y * rhs._y;
	}

	friend Vector2f operator*(const Vector2f & lhs, float scalar)
	{
		return Vector2f(lhs._x * scalar, lhs._y * scalar);
	}

private:
	float _x;
	float _y;

	friend std::ostream & operator<<(std::ostream & out, const Vector2f & rhs)
	{
		return out << rhs.getX() << " " << rhs.getY();
	}
};
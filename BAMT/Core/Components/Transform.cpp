#include "Transform.h"

#include <cmath>

namespace VectorMath
{
	float Distance(const Vector2& v1, const Vector2& v2)
	{
		const float x = pow(v2.x - v1.x, 2);
		const float y = pow(v2.y - v1.y, 2);
		return sqrt(x + y);
	}

	float Dot(const Vector2& v1, const Vector2& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	Vector2 Normalize(const Vector2& vector)
	{
		const float magnitude = Magnitude(vector);

		// If the Magnitude is zero. Return Zero.
		if (magnitude == 0)	return { 0,0 };

		return { vector.x / magnitude, vector.y / magnitude };
	}

	float Magnitude(const Vector2& vector)
	{
		return sqrt(vector.x * vector.x + vector.y * vector.y);
	}

	bool OverlapOnAxis(float pos1, float bounds1, float pos2, float bounds2)
	{
		const auto pos1Min = pos1 - bounds1 * 0.5f;
		const auto pos1Max = pos1 + bounds1 * 0.5f;

		const auto pos2Min = pos2 - bounds2 * 0.5f;
		const auto pos2Max = pos2 + bounds2 * 0.5f;

		if(pos1Min > pos2Max || pos1Max < pos2Min)
		{
			return false;
		}
		return true;
	}

	Vector2 Rotate(Vector2& direction, float angle)
	{
		// Get the cos and sin of the given angle.
		float cosAngle = cos(angle);
		float sinAngle = sin(angle);

		// Use those to rotate the vector.
		float newX = direction.x * cosAngle - direction.y * sinAngle;
		float newY = direction.x * sinAngle + direction.y * cosAngle;

		// Return it!
		return { newX, newY };
	}
}

bool Vector2::operator==(const Vector2& vector) const
{
	return this->x == vector.x && this->y == vector.y;
}

Vector2 Vector2::operator-(const Vector2& vector) const
{
	return {this->x - vector.x, this->y - vector.y};
}

Vector2 Vector2::operator*(const Vector2& vector) const
{
	return { this->x * vector.x, this->y * vector.x };
}

Vector2 Vector2::operator*(const float multiplier) const
{
	return { this->x * multiplier, this->y * multiplier };
}

// Implement the multiplication operator overload.
Vector2 operator*(const float multiplier, const Vector2& vector)
{
	return { multiplier * vector.x, multiplier * vector.y };
}

Vector2 Vector2::operator/(const float divider) const
{
	return { this->x / divider, this->y / divider };
}

Vector2 Vector2::operator+(const Vector2& vector) const
{
	return { this->x + vector.x, this->y + vector.x };
}

Transform::Transform(float x, float y) : _position(new Vector2{ x, y }){ }

void Transform::SetX(float x) const { _position->x = x; }

void Transform::SetY(float y) const { _position->y = y; }

float Transform::GetX() const { return _position->x; }

float Transform::GetY() const { return _position->y; }

void Transform::Translate(int x, int y) const
{
	_position->x += x;
	_position->y += y;
}

void Transform::Translate(float x, float y) const
{
	_position->x += x;
	_position->y += y;
}

void Transform::SetPosition(float x, float y) const
{
	_position->x = x;
	_position->y = y;
}

void Transform::SetPosition(const Vector2* position) const
{
	_position->x = position->x;
	_position->y = position->y;
}

Vector2* Transform::GetPosition() const
{
	return _position;
}
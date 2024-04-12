#include "Transform.h"

#include <cmath>

namespace VectorMath
{
	float Distance(const Vector2& v1, const Vector2& v2)
	{
		const float x = (float)pow(v2.x - v1.x, 2);
		const float y = (float)pow(v2.y - v1.y, 2);
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
		if (magnitude == 0.f) return { 0,0 };

		return { vector.x / magnitude, vector.y / magnitude };
	}

	float Magnitude(const Vector2& vector)
	{
		return sqrt(vector.x * vector.x + vector.y * vector.y);
	}

	bool OverlapOnAxis(const float pos1, const float bounds1, const float pos2, const float bounds2)
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

	Vector2 Rotate(const Vector2& direction, const float angle)
	{
		// Get the cos and sin of the given angle.
		const float cosAngle = cos(angle);
		const float sinAngle = sin(angle);

		// Use those to rotate the vector.
		const float newX = direction.x * cosAngle - direction.y * sinAngle;
		const float newY = direction.x * sinAngle + direction.y * cosAngle;

		// Return it!
		return { newX, newY };
	}
}

bool Vector2::operator==(const Vector2& vector) const
{
	// Since floats arent always 100% accurate, we need to use a tolerance.
	constexpr float tolerance = 1e-5f; 
	return fabs(this->x - vector.x) < tolerance && fabs(this->y - vector.y) < tolerance;
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

Transform::Transform(const float x, const float y) : _position(new Vector2{ x, y }){ }

void Transform::SetX(const float x) const { _position->x = x; }

void Transform::SetY(const float y) const { _position->y = y; }

float Transform::GetX() const { return _position->x; }

float Transform::GetY() const { return _position->y; }

void Transform::Translate(const int x, const int y) const
{
	_position->x += (float)x;
	_position->y += (float)y;
}

void Transform::Translate(const float x, const float y) const
{
	_position->x += x;
	_position->y += y;
}

void Transform::SetPosition(const float x, const float y) const
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
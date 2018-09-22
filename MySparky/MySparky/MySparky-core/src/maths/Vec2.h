#pragma once
#include <iostream>

namespace mysparky
{
	namespace maths
	{
		struct Vec2
		{
			float m_X, m_Y;

			Vec2() : m_X(0.0f), m_Y(0.0f) {};
			Vec2(const float x, const float y) : m_X(x), m_Y(y) {};

			Vec2& Add(const Vec2& other);
			Vec2& Subtract(const Vec2& other);
			Vec2& Multiply(const Vec2& other);
			Vec2& Divide(const Vec2& other);

			Vec2 operator+(const Vec2& rhs) const { return Vec2(m_X + rhs.m_X, m_Y + rhs.m_Y); };
			Vec2 operator-(const Vec2& rhs) const { return Vec2(m_X - rhs.m_X, m_Y - rhs.m_Y); };
			Vec2 operator*(const Vec2& rhs) const { return Vec2(m_X * rhs.m_X, m_Y * rhs.m_Y); };
			Vec2 operator/(const Vec2& rhs) const { return Vec2(m_X / rhs.m_X, m_Y / rhs.m_Y); };

			bool operator==(const Vec2& other);
			bool operator!=(const Vec2& other);

			Vec2 operator+=(const Vec2& rhs);
			Vec2 operator-=(const Vec2& rhs);
			Vec2 operator*=(const Vec2& rhs);
			Vec2 operator/=(const Vec2& rhs);

			friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector);
		};
	}
}
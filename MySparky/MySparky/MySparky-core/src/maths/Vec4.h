#pragma once
#include <iostream>

namespace mysparky::maths
{
	struct Vec4
	{
		float m_X, m_Y, m_Z, m_W;

		Vec4() :m_X(0.0f), m_Y(0.0f), m_Z(0.0f), m_W(0.0f) {};
		Vec4(const float x, const float y, const float z, const float w) : m_X(x), m_Y(y), m_Z(z), m_W(w) {};

		Vec4& Add(const Vec4& other);
		Vec4& Subtract(const Vec4& other);
		Vec4& Multiply(const Vec4& other);
		Vec4& Divide(const Vec4& other);

		Vec4 operator+(const Vec4& rhs) const { return Vec4(m_X + rhs.m_X, m_Y + rhs.m_Y, m_Z + rhs.m_Z, m_W + rhs.m_W); };
		Vec4 operator-(const Vec4& rhs) const { return Vec4(m_X - rhs.m_X, m_Y - rhs.m_Y, m_Z - rhs.m_Z, m_W - rhs.m_W); };
		Vec4 operator*(const Vec4& rhs) const { return Vec4(m_X * rhs.m_X, m_Y * rhs.m_Y, m_Z * rhs.m_Z, m_W * rhs.m_W); };
		Vec4 operator/(const Vec4& rhs) const { return Vec4(m_X / rhs.m_X, m_Y / rhs.m_Y, m_Z / rhs.m_Z, m_W / rhs.m_W); };

		bool operator==(const Vec4& other);
		bool operator!=(const Vec4& other);

		Vec4 operator+=(const Vec4& rhs);
		Vec4 operator-=(const Vec4& rhs);
		Vec4 operator*=(const Vec4& rhs);
		Vec4 operator/=(const Vec4& rhs);

		friend std::ostream& operator<<(std::ostream& stream, const Vec4& vector);
	};
}
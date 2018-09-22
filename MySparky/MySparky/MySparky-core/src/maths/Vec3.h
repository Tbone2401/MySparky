#pragma once
#include <iostream>

namespace mysparky::maths
{
	struct Vec3
	{
		float m_X, m_Y, m_Z;

		Vec3() : m_X(0.0f), m_Y(0.0f), m_Z(0.0f) {};
		Vec3(const float x, const float y, const float z) : m_X(x), m_Y(y), m_Z(z) {};

		Vec3& Add(const Vec3& other);
		Vec3& Subtract(const Vec3& other);
		Vec3& Multiply(const Vec3& other);
		Vec3& Divide(const Vec3& other);

		Vec3 operator+(const Vec3& rhs) const { return Vec3(m_X + rhs.m_X, m_Y + rhs.m_Y, m_Z + rhs.m_Z); };
		Vec3 operator-(const Vec3& rhs) const { return Vec3(m_X - rhs.m_X, m_Y - rhs.m_Y, m_Z - rhs.m_Z); };
		Vec3 operator*(const Vec3& rhs) const { return Vec3(m_X * rhs.m_X, m_Y * rhs.m_Y, m_Z * rhs.m_Z); };
		Vec3 operator/(const Vec3& rhs) const { return Vec3(m_X / rhs.m_X, m_Y / rhs.m_Y, m_Z / rhs.m_Z); };

		bool operator==(const Vec3& other);
		bool operator!=(const Vec3& other);

		Vec3 operator+=(const Vec3& rhs);
		Vec3 operator-=(const Vec3& rhs);
		Vec3 operator*=(const Vec3& rhs);
		Vec3 operator/=(const Vec3& rhs);

		friend std::ostream& operator<<(std::ostream& stream, const Vec3& vector);
	};
}
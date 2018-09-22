#include "vec2.h"
namespace mysparky::maths
{
	Vec2 & Vec2::Add(const Vec2 & other)
	{
		m_X += other.m_X;
		m_Y += other.m_Y;

		return *this;
	}
	Vec2 & Vec2::Subtract(const Vec2 & other)
	{
		m_X -= other.m_X;
		m_Y -= other.m_Y;

		return *this;
	}
	Vec2 & Vec2::Multiply(const Vec2 & other)
	{
		m_X *= other.m_X;
		m_Y *= other.m_Y;

		return *this;
	}
	Vec2 & Vec2::Divide(const Vec2 & other)
	{
		m_X /= other.m_X;
		m_Y /= other.m_Y;

		return *this;
	}
	bool Vec2::operator==(const Vec2 & other)
	{
		return other.m_X == m_X && other.m_Y == m_Y;
	}
	bool Vec2::operator!=(const Vec2 & other)
	{
		return !(*this == other);
	}
	Vec2 Vec2::operator+=(const Vec2 & rhs)
	{
		return this->Add(rhs);
	}
	Vec2 Vec2::operator-=(const Vec2 & rhs)
	{
		return this->Subtract(rhs);
	}
	Vec2 Vec2::operator*=(const Vec2 & rhs)
	{
		return this->Multiply(rhs);
	}
	Vec2 Vec2::operator/=(const Vec2 & rhs)
	{
		return this->Divide(rhs);
	}
	std::ostream & operator<<(std::ostream & stream, const Vec2 & vector)
	{
		stream << "vec2: (" << vector.m_X << ", " << vector.m_Y << ")";
		return stream;
	}
}

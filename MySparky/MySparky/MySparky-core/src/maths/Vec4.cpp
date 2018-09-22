#include "Vec4.h"
namespace mysparky::maths
{
	Vec4 & Vec4::Add(const Vec4 & other)
	{
		m_X += other.m_X;
		m_Y += other.m_Y;
		m_Z += other.m_Z;
		m_W += other.m_W;

		return *this;
	}
	Vec4 & Vec4::Subtract(const Vec4 & other)
	{
		m_X -= other.m_X;
		m_Y -= other.m_Y;
		m_Z -= other.m_Z;
		m_W -= other.m_W;

		return *this;
	}
	Vec4 & Vec4::Multiply(const Vec4 & other)
	{
		m_X *= other.m_X;
		m_Y *= other.m_Y;
		m_Z *= other.m_Z;
		m_W *= other.m_W;

		return *this;
	}
	Vec4 & Vec4::Divide(const Vec4 & other)
	{
		m_X /= other.m_X;
		m_Y /= other.m_Y;
		m_Z /= other.m_Z;
		m_W /= other.m_W;

		return *this;
	}
	bool Vec4::operator==(const Vec4 & other)
	{
		return other.m_X == m_X && other.m_Y == m_Y && other.m_Z == m_Z && other.m_W == m_W;
	}
	bool Vec4::operator!=(const Vec4 & other)
	{
		return !(*this == other);
	}
	Vec4 Vec4::operator+=(const Vec4 & rhs)
	{
		return this->Add(rhs);
	}
	Vec4 Vec4::operator-=(const Vec4 & rhs)
	{
		return this->Subtract(rhs);
	}
	Vec4 Vec4::operator*=(const Vec4 & rhs)
	{
		return this->Multiply(rhs);
	}
	Vec4 Vec4::operator/=(const Vec4 & rhs)
	{
		return this->Divide(rhs);
	}
	std::ostream & operator<<(std::ostream & stream, const Vec4 & vector)
	{
		stream << "Vec4: (" << vector.m_X << ", " << vector.m_Y << ", " << vector.m_Z << ", " << vector.m_W << ")";
		return stream;
	}
}

#include "Vec3.h"
namespace mysparky::maths
{
	Vec3 & Vec3::Add(const Vec3 & other)
	{
		m_X += other.m_X;
		m_Y += other.m_Y;
		m_Z += other.m_Z;

		return *this;
	}
	Vec3 & Vec3::Subtract(const Vec3 & other)
	{
		m_X -= other.m_X;
		m_Y -= other.m_Y;
		m_Z -= other.m_Z;

		return *this;
	}
	Vec3 & Vec3::Multiply(const Vec3 & other)
	{
		m_X *= other.m_X;
		m_Y *= other.m_Y;
		m_Z *= other.m_Z;

		return *this;
	}
	Vec3 & Vec3::Divide(const Vec3 & other)
	{
		m_X /= other.m_X;
		m_Y /= other.m_Y;
		m_Z /= other.m_Z;

		return *this;
	}
	bool Vec3::operator==(const Vec3 & other)
	{
		return other.m_X == m_X && other.m_Y == m_Y && other.m_Z == m_Z;
	}
	bool Vec3::operator!=(const Vec3 & other)
	{
		return !(*this == other);
	}
	Vec3 Vec3::operator+=(const Vec3 & rhs)
	{
		return this->Add(rhs);
	}
	Vec3 Vec3::operator-=(const Vec3 & rhs)
	{
		return this->Subtract(rhs);
	}
	Vec3 Vec3::operator*=(const Vec3 & rhs)
	{
		return this->Multiply(rhs);
	}
	Vec3 Vec3::operator/=(const Vec3 & rhs)
	{
		return this->Divide(rhs);
	}
	std::ostream & operator<<(std::ostream & stream, const Vec3 & vector)
	{
		stream << "Vec3: (" << vector.m_X << ", " << vector.m_Y << ", " << vector.m_Z << ")";
		return stream;
	}
}
#include "Mat4.h"

namespace mysparky::maths
{
	Mat4::Mat4()
	{
		for (int i = 0; i < C_Mat_Size; i++)
		{
			m_Elements[i] = 0.0f;
		}
	}

	Mat4::Mat4(float diagonal)
	{
		for (int i = 0; i < C_Mat_Size; i++)
		{
			m_Elements[i] = 0.0f;
		}
		m_Elements[0 + 0 * C_Mat_Dimension] = diagonal;
		m_Elements[1 + 1 * C_Mat_Dimension] = diagonal;
		m_Elements[2 + 2 * C_Mat_Dimension] = diagonal;
		m_Elements[3 + 3 * C_Mat_Dimension] = diagonal;
	}

	Mat4& Mat4::Multiply(const Mat4 & other)
	{
		for (size_t y = 0; y < C_Mat_Dimension; y++)
		{
			for (size_t x = 0; x < C_Mat_Dimension; x++)
			{
				float sum = 0.0f;
				for (size_t e = 0; e < C_Mat_Dimension; e++)
				{
					sum += m_Elements[x + e * 4] * other.m_Elements[e + y * C_Mat_Dimension];
				}
				m_Elements[x + y * 4] = sum;
			}
		}
		return *this;
	}

	Mat4 Mat4::operator*(const Mat4 & rhs) const
	{
		Mat4 result;
		for (size_t y = 0; y < C_Mat_Dimension; y++)
		{
			for (size_t x = 0; x < C_Mat_Dimension; x++)
			{
				float sum = 0.0f;
				for (size_t e = 0; e < C_Mat_Dimension; e++)
				{
					sum += m_Elements[x + e * 4] * rhs.m_Elements[e + y * C_Mat_Dimension];
				}
				result.m_Elements[x + y * 4] = sum;
			}
		}
		return result;
	}

	Mat4 Mat4::operator*=(const Mat4 & rhs)
	{
		return Multiply(rhs);
	}
	Mat4 Mat4::Identity()
	{
		return Mat4(1.0f);
	}

	Mat4 Mat4::Orthographic(float left, float right, float bottom, float top, float near, float far)
	{
		Mat4 result(1.0f);
		result.m_Elements[0 + 0 * C_Mat_Dimension] = 2.0f / (right - left);
		result.m_Elements[1 + 1 * C_Mat_Dimension] = 2.0f / (top - bottom);
		result.m_Elements[2 + 2 * C_Mat_Dimension] = 2.0f / (near - far);

		result.m_Elements[0 + 3 * C_Mat_Dimension] = (left + right) / (left - right);
		result.m_Elements[1 + 3 * C_Mat_Dimension] = (bottom + top) / (bottom - top);
		result.m_Elements[2 + 3 * C_Mat_Dimension] = (far + near) / (far - near);

		return result;
	}

	Mat4 Mat4::Perspective(float fov, float aspectRatio, float near, float far)
	{
		Mat4 result(1.0f);

		float q = 1.0f / tan(toRadians(0.5f * fov));
		float a = q / aspectRatio;
		float b = (near + far) / (near - far);
		float c = (2.0f * near + far) / (near - far);

		result.m_Elements[0 + 0 * C_Mat_Dimension] = a;
		result.m_Elements[1 + 1 * C_Mat_Dimension] = q;
		result.m_Elements[2 + 2 * C_Mat_Dimension] = b;
		result.m_Elements[3 + 2 * C_Mat_Dimension] = -1.0f;
		result.m_Elements[2 + 3 * C_Mat_Dimension] = c;

		return result;
	}

	Mat4 Mat4::Scale(const Vec3 & scale)
	{
		Mat4 result(1.0f);
		result.m_Elements[0 + 0 * C_Mat_Dimension] = scale.m_X;
		result.m_Elements[1 + 1 * C_Mat_Dimension] = scale.m_Y;
		result.m_Elements[2 + 2 * C_Mat_Dimension] = scale.m_Z;

		return result;
	}

	Mat4 Mat4::Rotation(float angle, const Vec3 & axis)
	{
		Mat4 result(1.0f);
		float r = toRadians(angle);
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;

		result.m_Elements[0 + 0 * C_Mat_Dimension] = axis.m_X * omc + c;
		result.m_Elements[1 + 0 * C_Mat_Dimension] = axis.m_Y * axis.m_X * omc + axis.m_Z * s;
		result.m_Elements[2 + 0 * C_Mat_Dimension] = axis.m_X * axis.m_Z * omc - axis.m_Y * s;

		result.m_Elements[0 + 1 * C_Mat_Dimension] = axis.m_X * axis.m_Y * omc - axis.m_Z * s;
		result.m_Elements[1 + 1 * C_Mat_Dimension] = axis.m_Y * omc + c;
		result.m_Elements[2 + 1 * C_Mat_Dimension] = axis.m_Y * axis.m_Z * omc + axis.m_X * s;

		result.m_Elements[0 + 2 * C_Mat_Dimension] = axis.m_X * axis.m_Z * omc + axis.m_Y * s;
		result.m_Elements[1 + 2 * C_Mat_Dimension] = axis.m_Y * axis.m_Z  * omc - axis.m_X * s;
		result.m_Elements[2 + 2 * C_Mat_Dimension] = axis.m_Z * omc + c;

		return result;
	}

	Mat4 Mat4::Translation(const Vec3 & translation)
	{
		Mat4 result(1.0f);
		result.m_Elements[0 + 3 * C_Mat_Dimension] = translation.m_X;
		result.m_Elements[1 + 3 * C_Mat_Dimension] = translation.m_Y;
		result.m_Elements[2 + 3 * C_Mat_Dimension] = translation.m_Z;

		return result;
	}

	Mat4::~Mat4()
	{
	}
}
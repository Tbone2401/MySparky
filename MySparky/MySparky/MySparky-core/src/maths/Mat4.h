#pragma once
#include "Maths.h"

namespace mysparky::maths
{
	constexpr int C_Mat_Size = 16;
	constexpr int C_Mat_Dimension = 4;

	struct Mat4
	{
	public:
		union
		{
			float m_Elements[C_Mat_Size];
			Vec4 m_Columns[C_Mat_Dimension];
		};
		Mat4();
		Mat4(float diagonal);

		Mat4& Multiply(const Mat4& other);

		static Mat4 Identity();
		static Mat4 Orthographic(float left, float right, float bottom, float top, float near, float far);
		static Mat4 Perspective(float fov, float aspectRatio, float near, float far);

		static Mat4 Scale(const Vec3& scale);
		static Mat4 Rotation(float angle, const Vec3& axis);
		static Mat4 Translation(const Vec3& translation);

		Mat4 operator*(const Mat4& rhs) const;
		Mat4 operator*=(const Mat4& rhs);
		~Mat4();
	};
}
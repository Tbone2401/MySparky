#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace mysparky::maths
{
	inline float toRadians(float degrees)
	{
		return degrees * (float)(M_PI / 180.0f);
	}
}
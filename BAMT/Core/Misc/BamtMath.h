#ifndef BAMT_MATH
#define BAMT_MATH

#include <cstdlib>

namespace Math
{
    float Clamp(float value, float minValue, float maxValue);

    float RandomFloat(float min, float max);
}
#endif
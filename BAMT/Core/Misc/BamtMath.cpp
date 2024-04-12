#include "BamtMath.h"

namespace Math
{
    float Clamp(float value, float minValue, float maxValue)
    {
        if (value < minValue)
        {
            return minValue;
        }
        if (value > maxValue)
        {
            return maxValue;
        }
        return value;
    }

    float RandomFloat(float min, float max)
    {
        float range = max - min;

        float random = (float)rand() / (float)RAND_MAX;

        return min + random * range;
    }
}

#include "framework/MathUtility.h"
#include <cmath>

namespace ly
{
    const float PI = 3.1415926535;
    sf::Vector2f RotationToVector(float rotation)
    {
        float radians = DegreesToRadians(rotation);
        // return sf::Vector2f(cos(radians), sin(radians));
        return sf::Vector2f(sin(radians), -cos(radians));
    }

    float DegreesToRadians(float degrees)
    {
        return degrees * (PI / 180.0f);
    }

    float RadiansToDegrees(float radians)
    {
        return radians * (180.0f / PI);
    }

}
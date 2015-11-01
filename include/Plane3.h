#pragma once
#include "Vector3.h"

namespace GPP
{
    class Plane3
    {
    public:
        Plane3(const Vector3& point0, const Vector3& point1, const Vector3& point2);
        Plane3(const Vector3& point, const Vector3& normal);
        ~Plane3();

        void GetParameters(Real parameters[4]) const;

    private:
        Plane3();

    private:
        Real mParameters[4];
    };
}

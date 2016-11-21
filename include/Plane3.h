/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "Vector3.h"

namespace GPP
{
    class GPP_EXPORT Plane3
    {
    public:
        Plane3();
        Plane3(Real parameters[4]);
        Plane3(const Vector3& point0, const Vector3& point1, const Vector3& point2);
        Plane3(const Vector3& point, const Vector3& normal);
        ~Plane3();

        void GetParameters(Real parameters[4]) const;
        Real SignedDistance(const Vector3& point) const;
        Vector3 Intersection(const Vector3& startPoint, const Vector3& endPoint, Real* ratio) const;

    private:
        Real mParameters[4];
    };
}

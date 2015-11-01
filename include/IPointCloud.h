#pragma once
#include "Vector3.h"

namespace GPP
{
    class GPP_EXPORT IPointCloud
    {
    public:
        IPointCloud(){}

        virtual Int GetPointCount() const = 0;
        virtual Vector3 GetPointCoord(Int pid) const = 0;
        virtual void SetPointCoord(Int pid, const Vector3& coord) = 0;
        virtual Vector3 GetPointNormal(Int pid) const = 0;
        virtual void SetPointNormal(Int pid, const Vector3& normal) = 0;
        virtual bool HasNormal() const = 0;
        virtual void SetHasNormal(bool has) = 0;

        virtual ~IPointCloud(){};
    };
}

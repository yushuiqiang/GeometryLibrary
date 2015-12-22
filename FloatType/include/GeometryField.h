#pragma once
#include "IPointList.h"

namespace GPP
{
    class GeometryField
    {
    public:
        GeometryField();
        ~GeometryField();

        static ErrorCode CalculateFlatness(const IPointList* pointList, Real* flatness);

    };
}

/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT DigitalRelief
    {
    public:
        DigitalRelief();
        ~DigitalRelief();

        // compressRatio: (REAL_TOL, 1], smaller value will compress more
        static ErrorCode CompressHeightField(std::vector<Real>* heightField, Int resolutionX, Int resolutionY, Real compressRatio);

    };
}

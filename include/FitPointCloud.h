/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "IPointCloud.h"
#include "IPointList.h"
#include "Plane3.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT FitPointCloud
    {
    public:
        FitPointCloud();
        ~FitPointCloud();

        static ErrorCode UniformFit(IPointCloud* pointCloud, const IPointList* refPointList, Real supportInterval, Int iterationCount);

    };
}

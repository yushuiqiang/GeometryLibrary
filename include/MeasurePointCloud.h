/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "IPointList.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT MeasurePointCloud
    {
    public:
        MeasurePointCloud();
        ~MeasurePointCloud();

        static ErrorCode ComputeOneSideDistance(const IPointList* pointListRef, const IPointList* pointListFrom, 
            Real& maxDistance, Int& maxPointId, std::vector<Real>* fromDistance = NULL);
    };
}

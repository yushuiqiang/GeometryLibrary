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
            Real& maxDistance, Int& maxPointId, Real* fromDistance = NULL);
    };
}

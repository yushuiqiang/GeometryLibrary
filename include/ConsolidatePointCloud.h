#pragma once
#include "IPointCloud.h"

namespace GPP
{
    class GPP_EXPORT ConsolidatePointCloud
    {
    public:
        ConsolidatePointCloud();
        ~ConsolidatePointCloud();

        static ErrorCode LaplaceSmooth(IPointCloud* pointCloud, Real percentage, Int times);

        static ErrorCode CalculatePointCloudNormal(IPointCloud* pointCloud, Int quality = 0);
    };
}

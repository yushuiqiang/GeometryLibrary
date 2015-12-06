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

        // isolation should allocate memory first
        // isolation value is between [0, 1], smaller value means more isolated
        // pointCloud shoud have normal
        static ErrorCode CalculateIsolation(const IPointCloud* pointCloud, Real* isolation);
    };
}

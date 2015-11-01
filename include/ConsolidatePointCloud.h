#pragma once
#include "IPointCloud.h"

namespace GPP
{
    class GPP_EXPORT ConsolidatePointCloud
    {
    public:
        ConsolidatePointCloud();
        ~ConsolidatePointCloud();

        static Int LaplaceSmooth(IPointCloud* pointCloud, Real percentage, Int times);

        static Int CalculatePointCloudNormal(IPointCloud* pointCloud, Int quality = 0);
    };
}

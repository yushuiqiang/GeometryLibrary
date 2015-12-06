#pragma once
#include "GppDefines.h"
#include <vector>

namespace GPP
{
    class IPointCloud;
    class PointCloud;

    extern GPP_EXPORT PointCloud* CopyPointCloud(const PointCloud* pointCloud);

    extern GPP_EXPORT ErrorCode DeletePointCloudElements(IPointCloud* pointCloud, const std::vector<Int>& deleteIndex);
}

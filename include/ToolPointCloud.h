#pragma once
#include "GppDefines.h"
#include <vector>

namespace GPP
{
    class PointCloud;

    extern GPP_EXPORT PointCloud* CopyPointCloud(const PointCloud* pointCloud);
}

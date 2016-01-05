#pragma once
#include "IPointCloud.h"

namespace GPP
{
    class GPP_EXPORT ConsolidatePointCloud
    {
    public:
        ConsolidatePointCloud();
        ~ConsolidatePointCloud();

        // If pointCloud is depth image, result normal will face z positive direction, speed is faster
        static ErrorCode CalculatePointCloudNormal(IPointCloud* pointCloud, bool isDepthImage = false);

        // pointCloud should have normals
        // normalWeight: (0, +). Larger value will smooth less.
        static ErrorCode SmoothNormal(IPointCloud* pointCloud, Real normalWeight = 1.0);

        // pointCloud should have normals
        // Geometry will be modified to match normal
        static ErrorCode SmoothGeometryByNormal(IPointCloud* pointCloud);

        // isolation should allocate memory first
        // isolation value is between [0, 1], smaller value means more isolated
        // pointCloud shoud have normals
        static ErrorCode CalculateIsolation(const IPointCloud* pointCloud, Real* isolation);

    };
}

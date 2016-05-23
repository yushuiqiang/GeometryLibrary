/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "IPointCloud.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT ConsolidatePointCloud
    {
    public:
        ConsolidatePointCloud();
        ~ConsolidatePointCloud();

        // If pointCloud is depth image, result normal will face z positive direction, speed is faster
        static ErrorCode CalculatePointCloudNormal(IPointCloud* pointCloud, bool isDepthImage = false);


        static ErrorCode ReversePatchNormal(IPointCloud* pointCloud, Int pointId);

        // pointCloud should have normals
        // normalWeight: (REAL_TOL, +). Larger value will smooth less.
        static ErrorCode SmoothNormal(IPointCloud* pointCloud, Real normalWeight = 1.0);

        // pointCloud should have normals
        // Geometry will be modified to match normal
        static ErrorCode SmoothGeometryByNormal(IPointCloud* pointCloud);

        // isolation value is between [0, 1], smaller value means more isolated
        // pointCloud shoud have normals
        static ErrorCode CalculateIsolation(const IPointCloud* pointCloud, std::vector<Real>* isolation);

        // uniformaity value is between [0, 1], smaller value means more uniform
        // pointCloud doesn't need to have normals
        static ErrorCode CalculateUniformity(const IPointCloud* pointCloud, std::vector<Real>* uniformaity);

        // 1. remove points whose z > -REAL_TOL if zPositive == false
        //    remove points whose z <  REAL_TOL if zPositive == true
        // 2. remove outlier (optional)
        // 3. calculate normal
        // pointCloud is form left up corner to right down corner
        static ErrorCode ConsolidateRawScanData(IPointCloud* pointCloud, Int resolutionX, Int resolutionY, bool removeOutlier, bool zPositive);

    };
}

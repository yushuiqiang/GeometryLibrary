/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "PointCloud.h"
#include "IPointList.h"
#include <vector>

namespace GPP
{
    extern GPP_EXPORT PointCloud* CopyPointCloud(const PointCloud* pointCloud);

    extern GPP_EXPORT ErrorCode DeletePointCloudElements(IPointCloud* pointCloud, const std::vector<Int>& deleteIndex);

    extern GPP_EXPORT ErrorCode CalculatePointListBoundingBox(const IPointList* pointlist, Vector3& bboxMin, Vector3& bboxMax);

    extern GPP_EXPORT ErrorCode CalculatePointListDensity(const IPointList* pointList, Real& density);
}

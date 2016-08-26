/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "PointCloud.h"
#include "IPointList.h"
#include "Matrix4x4.h"
#include <vector>

namespace GPP
{
    extern GPP_EXPORT PointCloud* CopyPointCloud(const PointCloud* pointCloud);

    // deleteIndex could have duplicate index
    extern GPP_EXPORT ErrorCode DeletePointCloudElements(IPointCloud* pointCloud, const std::vector<Int>& deleteIndex);

    extern GPP_EXPORT ErrorCode CalculatePointListBoundingBox(const IPointList* pointlist, Vector3& bboxMin, Vector3& bboxMax);

    extern GPP_EXPORT ErrorCode CalculatePointCloudListBoundingBox(const std::vector<IPointCloud*> pointCloudList, 
        const std::vector<Matrix4x4>* transformList, Vector3& bboxMin, Vector3& bboxMax);

    extern GPP_EXPORT ErrorCode CalculatePointListDensity(const IPointList* pointList, Int neighborCount, Real& density);

    // pointCloud should have normal, and this function just update normal and the orientation is the same as before
    extern GPP_EXPORT ErrorCode UpdatePointCloudNormal(IPointCloud* pointCloud, Int neighborCount);

    // pointCloud should have normal
    // pointCloud should be depth data
    // maxZAngle: (0, 90 * ONE_RADIAN). Remove points whose normal z(positive) in cameral coordinate is less than cos(maxZAngle)
    // if cameraDir == NULL, it will use average point cloud normal as cameraDir. 
    // If point cloud is in depth cordinate system, cameraDir may be (0, 0, 1) or (0, 0, -1)
    extern GPP_EXPORT ErrorCode DetectBoundaryPointByZAngle(IPointCloud* pointCloud, Real maxZAngle, const Vector3* cameraDir, 
        std::vector<Int>& boundaryIds);


    // pointCloud should be depth data and have no transform in the world
    // boundarySize >= 1.0, larger value will make boundary size larger
    extern GPP_EXPORT ErrorCode DetectBoundaryPointByZProjection(IPointCloud* pointCloud, Real boundarySize, std::vector<Int>& boundaryIds);

}

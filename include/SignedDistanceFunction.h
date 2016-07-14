/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "IPointCloud.h"
#include "Matrix4x4.h"

namespace GPP
{
    struct SdfTree;

    class GPP_EXPORT SignedDistanceFunction
    {
    public:
        SignedDistanceFunction();
        explicit SignedDistanceFunction(Int resolutionX, Int resolutionY, Int resolutionZ, const Vector3& bboxMin, const Vector3& bboxMax);
        
        ~SignedDistanceFunction();

        void Init(Int resolutionX, Int resolutionY, Int resolutionZ, const Vector3& bboxMin, const Vector3& bboxMax);

        ErrorCode UpdateFunction(const IPointCloud* pointCloud, const Matrix4x4* transform);

        // pointCloud should allocate memory first and be blank
        ErrorCode ExtractPointCloud(IPointCloud* pointCloud);
        
        void Clear(void);

        // They are just for debug, user could ignore it.
        ErrorCode DumpInfo(std::ofstream& dumpOut) const;
        ErrorCode LoadInfo(std::ifstream& loadIn);

    private:
        SdfTree* mpSdfTree;
        Int mResolutionX;
        Int mResolutionY;
        Int mResolutionZ;
        Vector3 mBBoxMin;
        Vector3 mBBoxMax;
    };


}
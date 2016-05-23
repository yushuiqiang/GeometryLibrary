/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "IPointCloud.h"
#include "Matrix4x4.h"
#include <vector>
#include <fstream>

namespace GPP
{
    struct SumTree;

    class GPP_EXPORT SumPointCloud
    {
    public:
        SumPointCloud();
        explicit SumPointCloud(Int resolutionX, Int resolutionY, Int resolutionZ, 
            const Vector3& bboxMin, const Vector3& bboxMax, bool hasNormalInfo);
        ~SumPointCloud();

        void Init(Int resolutionX, Int resolutionY, Int resolutionZ, const Vector3& bboxMin, const Vector3& bboxMax, bool hasNormalInfo);

        // initTransform == NULL if initTransform is identity
        ErrorCode UpdateSumFunction(const IPointCloud* pointCloud, const Matrix4x4* transform, const std::vector<Real>* pointFields = NULL);

        // pointCloud should allocate memory first and be blank
        ErrorCode ExtractPointCloud(IPointCloud* pointCloud, std::vector<Real>* pointFields = NULL);
        
        void Clear(void);

        // They are just for debug, user could ignore it.
        ErrorCode DumpInfo(std::ofstream& dumpOut) const;
        ErrorCode LoadInfo(std::ifstream& loadIn);
        

    private:
        SumTree* mpSumTree;
        Int mResolutionX;
        Int mResolutionY;
        Int mResolutionZ;
        Vector3 mBBoxMin;
        Vector3 mBBoxMax;
        bool mHasNormalInfo;
        Int mCloudId;
    };
}

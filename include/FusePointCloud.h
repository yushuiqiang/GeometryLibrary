/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "IPointCloud.h"
#include "IPointList.h"
#include "Matrix4x4.h"
#include <vector>
#include <fstream>

namespace GPP
{
    struct FuseTree;

    class GPP_EXPORT FusePointCloud
    {
    public:
        FusePointCloud();
        explicit FusePointCloud(Int resolutionX, Int resolutionY, Int resolutionZ, 
            const Vector3& bboxMin, const Vector3& bboxMax, bool hasNormalInfo);
        ~FusePointCloud();

        void Init(Int resolutionX, Int resolutionY, Int resolutionZ, const Vector3& bboxMin, const Vector3& bboxMax, bool hasNormalInfo);

        // initTransform == NULL if initTransform is identity
        ErrorCode UpdateFuseFunction(const IPointCloud* pointCloud, const Matrix4x4* transform, const std::vector<Real>* pointFields = NULL);
        
        // Internal use api
        ErrorCode _UpdateFuseFunction(const IPointList* pointList, const Matrix4x4* transform, const std::vector<Real>* pointFields = NULL);

        // pointCloud should allocate memory first and be blank
        ErrorCode ExtractPointCloud(IPointCloud* pointCloud, std::vector<Real>* pointFields = NULL);
        
        void Clear(void);

        // Internal use api
        // They are just for debug, user could ignore it.
        ErrorCode DumpInfo(std::ofstream& dumpOut) const;
        ErrorCode LoadInfo(std::ifstream& loadIn);
        

    private:
        FuseTree* mpFuseTree;
        Int mResolutionX;
        Int mResolutionY;
        Int mResolutionZ;
        Vector3 mBBoxMin;
        Vector3 mBBoxMax;
        bool mHasNormalInfo;
    };
}

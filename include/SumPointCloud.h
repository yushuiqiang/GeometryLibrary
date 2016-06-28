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
        explicit SumPointCloud(Real interval, const Vector3& bboxMin, const Vector3& bboxMax, bool hasNormalInfo);
        ~SumPointCloud();

        void Init(Real interval, const Vector3& bboxMin, const Vector3& bboxMax, bool hasNormalInfo);

        // initTransform == NULL if initTransform is identity
        ErrorCode UpdateSumFunction(const IPointCloud* pointCloud, const Matrix4x4* transform, const std::vector<Real>* pointFields = NULL);

        // pointCloud should allocate memory first and be blank
        ErrorCode ExtractPointCloud(IPointCloud* pointCloud, std::vector<Real>* pointFields = NULL, std::vector<Int>* cloudIds = NULL);

        // pointFields != NULL
        // baseCloudId: the first point cloud for sum
        // pointFields >= fieldsMin && pointFields <= fieldsMax
        ErrorCode ExtractPointCloudWithFusion(IPointCloud* pointCloud, std::vector<Real>* pointFields, Int baseCloudId = 0, 
            Int neighborCount = 12, const std::vector<Real>* fieldsMin = NULL, const std::vector<Real>* fieldsMax = NULL,
            std::vector<Int>* cloudIds = NULL);
        
        void Clear(void);

        // They are just for debug, user could ignore it.
        ErrorCode DumpInfo(std::ofstream& dumpOut) const;
        ErrorCode LoadInfo(std::ifstream& loadIn);
        

    private:
        SumTree* mpSumTree;
        Real mInterval;
        Vector3 mBBoxMin;
        Vector3 mBBoxMax;
        bool mHasNormalInfo;
        Int mCloudId;
    };
}

#pragma once
#include "IPointCloud.h"
#include "Matrix4x4.h"
#include <vector>

namespace GPP
{
    struct SdfTree;
    class GPP_EXPORT FusePointCloud
    {
    public:
        explicit FusePointCloud(Int resolutionX, Int resolutionY, Int resolutionZ, const Vector3& bboxMin, const Vector3& bboxMax);
        ~FusePointCloud();

        // initTransform == NULL if initTransform is identity
        ErrorCode UpdateFuseFunction(const IPointCloud* pointCloud, const Matrix4x4* transform);

        // pointCloud should allocate memory first and be blank
        ErrorCode ExtractPointCloud(IPointCloud* pointCloud);
        
        void Clear(void);

        void DumpInfo(std::ofstream& dumpOut) const;
        void LoadInfo(std::ifstream& loadIn);

    private:
        FusePointCloud();

    private:
        SdfTree* mpSdfTree;
        Int mResolutionX;
        Int mResolutionY;
        Int mResolutionZ;
        Vector3 mBBoxMin;
        Vector3 mBBoxMax;
    };
}

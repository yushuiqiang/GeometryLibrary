#pragma once
#include "IPointCloud.h"
#include "Matrix4x4.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT RegistratePointCloud
    {
    public:
        RegistratePointCloud();
        ~RegistratePointCloud();

        // pointsRef = resultTransform * initTransform * pointsFrom;
        // initTransform == NULL if initTransform is identity
        // resultTransform should allocate memory before function calling
        static ErrorCode AlignByPointPairs(const std::vector<Vector3>& pointsRef, const std::vector<Vector3>& pointsFrom, Matrix4x4* resultTransform, const Matrix4x4* initTransform = NULL);

        // pointCloudRef = resultTransform * initTransform * pointCloudFrom;
        // initTransform == NULL if initTransform is identity
        // resultTransform should allocate memory before function calling
        // pointCloudRef and pointCloudFrom should have normal, if not, please calculate them first
        static ErrorCode ICPRegistrate(const IPointCloud* pointCloudRef, const IPointCloud* pointCloudFrom, Matrix4x4* resultTransform, const Matrix4x4* initTransform = NULL);
    };
}

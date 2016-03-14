#pragma once
#include "IPointCloud.h"
#include "IPointList.h"
#include "Matrix4x4.h"
#include <vector>

namespace GPP
{
    enum RegistrateQuality
    {
        REGISTRATE_QUALITY_LOW,
        REGISTRATE_QUALITY_HIGH
    };

    class GPP_EXPORT RegistratePointCloud
    {
    public:
        RegistratePointCloud();
        ~RegistratePointCloud();

        // pointsRes should be 1-1 mapping to pointsFrom
        // pointsRef = resultTransform * initTransform * pointsFrom;
        // initTransform == NULL if initTransform is identity
        // resultTransform should allocate memory before function calling
        static ErrorCode AlignPointPair(const std::vector<Vector3>& pointsRef, const std::vector<Vector3>& pointsFrom, Matrix4x4* resultTransform, const Matrix4x4* initTransform = NULL);

        // pointCloudRef = resultTransform * initTransform * pointCloudFrom;
        // pointCloudRef and pointCloudFrom should have normals, if not, please calculate them first
        // if there are no marks, please set marksRef = NULL, marksFrom = NULL
        // initTransform == NULL if initTransform is identity
        // resultTransform should allocate memory before function calling
        static ErrorCode ICPRegistrate(const IPointCloud* pointCloudRef, const std::vector<Vector3>* marksRef, 
            const IPointCloud* pointCloudFrom, const std::vector<Vector3>* marksFrom, 
            Matrix4x4* resultTransform, const Matrix4x4* initTransform = NULL);

        // pointCloudRef = resultTransform * pointCloudFrom;
        // pointCloudRef and pointCloudFrom should have normals, if not, please calculate them first
        // if there are no marks, please set marksRef = NULL, marksFrom = NULL
        // resultTransform should allocate memory before function calling
        // overlapRatio: if user could estimate the overlap ratiod here, the api may process faster
        static ErrorCode AlignPointCloud(const IPointCloud* pointCloudRef, const std::vector<Vector3>* marksRef, 
            const IPointCloud* pointCloudFrom, const std::vector<Vector3>* marksFrom, Matrix4x4* resultTransform, 
            RegistrateQuality quality = REGISTRATE_QUALITY_LOW, Real overlapRatio = 0.66);

        // pointCloudRef = resultTransform * pointCloudFrom;
        // pointCloudRef and pointCloudFrom should have normals, if not, please calculate them first
        // marksRef and marksFrom should have >= 3 points, no order requirement
        // resultTransform should allocate memory before function calling
        static ErrorCode AlignPointCloudByMark(const IPointCloud* pointCloudRef, const std::vector<Vector3>* marksRef, 
            const IPointCloud* pointCloudFrom, const std::vector<Vector3>* marksFrom, Matrix4x4* resultTransform);

        // pointCloud should have normals, if not, please calculate them first
        // needInitialAlignment: if point clouds are not aligned precisely, they need initial alignment
        // initTransform == NULL if initTransform is identity
        static ErrorCode GlobalRegistrate(const std::vector<IPointCloud*>* pointCloudList, bool needInitialAlignment,
            std::vector<Matrix4x4>* resultTransformList, const std::vector<Matrix4x4>* initTransformList = NULL);

    };
}

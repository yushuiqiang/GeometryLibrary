/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "IPointCloud.h"
#include "IPointList.h"
#include "Matrix4x4.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT RegistratePointCloud
    {
    public:
        RegistratePointCloud();
        ~RegistratePointCloud();

        // Internal use api
        // pointsRes should be 1-1 mapping to pointsFrom
        // pointsRef = resultTransform * initTransform * pointsFrom;
        // initTransform == NULL if initTransform is identity
        // resultTransform should allocate memory before function calling
        static ErrorCode _AlignPointPair(const std::vector<Vector3>& pointsRef, const std::vector<Vector3>& pointsFrom, 
            Matrix4x4* resultTransform, const Matrix4x4* initTransform = NULL);

        // pointCloudRef = resultTransform * initTransform * pointCloudFrom;
        // if there are no marks, please set marksRef = NULL, marksFrom = NULL
        // initTransform == NULL if initTransform is identity
        // resultTransform should allocate memory before function calling
        // hasNormalInfo: if pointCloudRef and pointCloudFrom have normal information, registrate result will be more accurate and fast
        static ErrorCode ICPRegistrate(const IPointCloud* pointCloudRef, const std::vector<Vector3>* marksRef, 
            const IPointCloud* pointCloudFrom, const std::vector<Vector3>* marksFrom, Matrix4x4* resultTransform, 
            const Matrix4x4* initTransform = NULL, bool hasNormalInfo = true);

        // pointCloudRef = resultTransform * pointCloudFrom;
        // pointCloudRef and pointCloudFrom should have normals, if not, please calculate them first
        // resultTransform should allocate memory before function calling
        // maxSampleTripleCount: larger value will get a more stale result, but performance will be lower
        static ErrorCode AlignPointCloud(const IPointCloud* pointCloudRef, const IPointCloud* pointCloudFrom, Matrix4x4* resultTransform, 
            Int maxSampleTripleCount = 500);

        // pointCloudRef = resultTransform * pointCloudFrom;
        // pointCloudRef and pointCloudFrom should have normals, if not, please calculate them first
        // marksRef and marksFrom should have >= 3 points, no order requirement
        // resultTransform should allocate memory before function calling
        static ErrorCode AlignPointCloudByMark(const IPointCloud* pointCloudRef, const std::vector<Vector3>* marksRef, 
            const IPointCloud* pointCloudFrom, const std::vector<Vector3>* marksFrom, Matrix4x4* resultTransform);

        // pointCloud should have normals, if not, please calculate them first
        // maxIterationCount > 0: 15 is fine usually.
        // initTransform == NULL if initTransform is identity
        // hasNormalInfo: if pointCloudList has normal information, registrate result will be more accurate and fast
        static ErrorCode GlobalRegistrate(const std::vector<IPointCloud*>* pointCloudList, Int maxIterationCount,
            std::vector<Matrix4x4>* resultTransformList, const std::vector<Matrix4x4>* initTransformList = NULL, 
            bool hasNormalInfo = true, Int fixId = 0, const std::vector<std::vector<Vector3> >* markList = NULL);

    };
}

/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "IPointList.h"
#include "Matrix4x4.h"
#include <vector>

namespace GPP
{
    class AnnImpl;
    class GPP_EXPORT Ann
    {
    public:
        Ann();
        ~Ann();

        ErrorCode Init(Real* refData, Int refCount, Int refDim);
        // This constructor could eliminate date duplication
        // If you want to use IPointCloud or ITriMesh here, please use PointCloudPointList, TriMeshPointList instead
        ErrorCode Init(const IPointList* pointList, const Matrix4x4* transform = NULL);

        ErrorCode InitWithNormal(const IPointList* pointList, Real coordScale, const Matrix4x4* transform = NULL);

        // distanceRes: Be careful, it is Square Length!
        // if indexRes or distanceRes is not needed, please set it as NULL
        ErrorCode FindNearestNeighbors(Real* searchData, Int searchCount, Int neighborCount, Int* indexRes, Real* distanceRes);

        // distanceRes: Be careful, it is Square Length!
        // if indexRes or distanceRes is not needed, please set it as NULL
        ErrorCode FindNearestNeighbors(const IPointList* pointList, Int neighborCount, Int* indexRes, Real* distanceRes);

        // radius: Be careful, squared radius of query ball
        // distanceRes: Be careful, it is Square Length!
        // if indexRes or distanceRes is not needed, please set it as NULL
        ErrorCode FindNearestNeighbors(Real* searchData, Real radius, std::vector<Int>* indexRes, std::vector<Real>* distanceRes);

        void Clear(void);

    private:
        AnnImpl* mpImpl;
    };
}

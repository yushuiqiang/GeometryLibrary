/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "IPointList.h"
#include "ITriMesh.h"
#include "IPointCloud.h"
#include <vector>
#include <set>

namespace GPP
{
    // Control points driven deformation: every control point has a rigid transform matrix Mi
    // Deformed Coord = Sum(Wi * Mi * OriginCoord)

    class GPP_EXPORT DeformPointList
    {
    public:
        DeformPointList();
        ~DeformPointList();
        
        // controlPointCount: if model has small number point, valid control point count may be less then controlPointCount
        ErrorCode Init(ITriMesh* triMesh, Int controlPointCount);

        ErrorCode Init(IPointCloud* pointCloud, Int controlPointCount);

        // constrainFlags: 0 - free, 1 - fixed
        // controlIndex and targetCoords are 1 - 1 correspondance, and they are used as position constraints in deformation
        ErrorCode Deform(const std::vector<Int>& controlIndex, const std::vector<Vector3>& targetCoords, 
            const std::vector<bool>& constrainFlags);

        void GetControlIds(std::vector<Int>& controlIds);

        void Clear(void);

        // This is just used for debugging, not for user
        std::vector<std::set<Int> > GetControlNeighbors(void);

    private:
        ITriMesh* mpTriMesh;
        IPointCloud* mpPointCloud;
        std::vector<Int> mControlIds;
        std::vector<std::set<Int> > mControlNeighbors;
        std::vector<std::vector<Real> > mControlWeights;
        std::vector<Int> mModelNeighbors;
        std::vector<Real> mModelWeights;
        Real mBBoxSize;
    };
}

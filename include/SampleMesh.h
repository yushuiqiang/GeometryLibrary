/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "TriMesh.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT SampleMesh
    {
    public:
        SampleMesh();
        ~SampleMesh();

        // points on the same face or edge are neighbors in pointsOnFace and pointsOnEdge
        // weights of points on the same edge are in ascending order 
        // sharpAngle: if edge faces' angle is larger than sharpAngle, the edge will be sharp edge. sharpAngle range (0, 180 * ONE_RADIAN)
        // pointsOnFace and pointsOnEdge should be strictly in face or edge, not on the boundary
        static ErrorCode UniformSample(const ITriMesh* triMesh, Int sampleCount, Real sharpAngle, std::vector<PointOnFace>& pointsOnFace, 
            std::vector<PointOnEdge>& pointsOnEdge, std::vector<Int>& pointsOnVertex, bool excludeBoundary);

    };
}

/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "ITriMesh.h"
#include <vector>
#include <map>

namespace GPP
{
    class GPP_EXPORT ConsolidateMesh
    {
    public:
        ConsolidateMesh();
        ~ConsolidateMesh();

        // Normal of result triMesh is not updated here
        // insertedVertexIdMap: inserted vertices are copied from original vertices, this map is from inserted vertex id to copied vertex id.
        static ErrorCode MakeTriMeshManifold(ITriMesh* triMesh, std::map<Int, Int>* insertVertexIdMap = NULL);

        // isolation value is between [0, 1], smaller value means more isolated
        static ErrorCode CalculateIsolation(const ITriMesh* triMesh, std::vector<Real>* isolation);

        // minEdgeLength: [REAL_TOL, +)
        // minTriangleAngle is radian: [REAL_TOL, 180 * ONE_RADIAN)
        // foldoverAngleTol is radian: [REAL_TOL, 180 * ONE_RADIAN)
        // Normal of result triMesh is not updated here
        static ErrorCode ConsolidateGeometry(ITriMesh* triMesh, Real minTriangleAngle, Real minEdgeLength, Real foldoverAngleTol);

        // sharpAngle is radian: (REAL_TOL, 180 * ONE_RADIAN)
        // positionWeight: (REAL_TOL, +). Larger value will smooth less
        // Normal of result triMesh is not updated here
        static ErrorCode RemoveGeometryNoise(ITriMesh* triMesh, Real sharpAngle = 70.0 * ONE_RADIAN, Real positionWeight = 1.0);

        // Internal use api
        static bool _IsTriMeshManifold(const ITriMesh* triMesh, Int* invalidVertexId = NULL);

        // Internal use api
        static bool _IsGeometryDegenerate(const ITriMesh* triMesh);
    };
}

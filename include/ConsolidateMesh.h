#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT ConsolidateMesh
    {
    public:
        ConsolidateMesh();
        ~ConsolidateMesh();

        static bool IsTriMeshManifold(const ITriMesh* triMesh);

        static ErrorCode MakeTriMeshManifold(ITriMesh* triMesh);

        // isolation value is between [0, 1], smaller value means more isolated
        static ErrorCode CalculateIsolation(ITriMesh* triMesh, std::vector<Real>* isolation);

        // minTriangleAngle is radian: (0, 180 * ONE_RADIAN)
        // foldoverAngleTol is radian: (0, 180 * ONE_RADIAN)
        static ErrorCode ConsolidateGeometry(ITriMesh* triMesh, Real minTriangleAngle, Real minEdgeLength, Real foldoverAngleTol);

        //sharpAngle is radian: (0, 180 * ONE_RADIAN)
        // positionWeight: (0, +). Larger value will smooth less.
        static ErrorCode RemoveGeometryNoise(ITriMesh* triMesh, Real sharpAngle = 70.0 * ONE_RADIAN, Real positionWeight = 1.0);
    };
}

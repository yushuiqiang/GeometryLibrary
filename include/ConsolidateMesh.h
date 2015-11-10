#pragma once
#include "ITriMesh.h"

namespace GPP
{
    class GPP_EXPORT ConsolidateMesh
    {
    public:
        ConsolidateMesh();
        ~ConsolidateMesh();

        static Int LaplaceSmooth(ITriMesh* triMesh, Real percentage, Int times, bool keepBoundary);

        static bool IsTriMeshManifold(ITriMesh* triMesh);

        static Int MakeTriMeshManifold(ITriMesh* triMesh);

        static Int ExtractLargeTriMeshPart(ITriMesh* triMesh, int partCount);

        static Int ConsolidateGeometry(ITriMesh* triMesh, Real minTriangleAngle, Real minEdgeLength, Real foldoverAngleTol);
    };
}

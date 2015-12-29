#pragma once
#include "ITriMesh.h"

namespace GPP
{
    class GPP_EXPORT ConsolidateMesh
    {
    public:
        ConsolidateMesh();
        ~ConsolidateMesh();

        static bool IsTriMeshManifold(const ITriMesh* triMesh);

        static ErrorCode MakeTriMeshManifold(ITriMesh* triMesh);

        static ErrorCode ExtractLargeTriMeshPart(ITriMesh* triMesh, int partCount);

        static ErrorCode ConsolidateGeometry(ITriMesh* triMesh, Real minTriangleAngle, Real minEdgeLength, Real foldoverAngleTol);
    };
}
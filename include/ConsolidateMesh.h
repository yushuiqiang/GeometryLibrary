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

        static Int MakeTriMeshManifold(ITriMesh* triMesh);

        static Int ExtractLargeTriMeshPart(ITriMesh* triMesh, int partCount);

        static Int ConsolidateGeometry(ITriMesh* triMesh, Real angleTol, Real edgeLengthTol, Int* singlarVertexModified);
    };
}

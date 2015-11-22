#pragma once
#include "ITriMesh.h"

namespace GPP
{
    class GPP_EXPORT SubdivideMesh
    {
    public:
        SubdivideMesh();
        ~SubdivideMesh();

        // Catmull-Clark subdivision
        static ErrorCode CCSubdivideMesh(ITriMesh* triMesh);

        static ErrorCode LoopSubdivideMesh(ITriMesh* triMesh);

        static ErrorCode RefineMesh(ITriMesh* triMesh, Int targetVertexCount);
    };
}

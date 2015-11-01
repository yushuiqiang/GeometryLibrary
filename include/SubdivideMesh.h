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
        static Int CCSubdivideMesh(ITriMesh* triMesh);

        static Int LoopSubdivideMesh(ITriMesh* triMesh);

        static Int RefineMesh(ITriMesh* triMesh, Int targetVertexCount);
    };
}

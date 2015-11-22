#pragma once
#include "ITriMesh.h"

namespace GPP
{
    class GPP_EXPORT SimplifyMesh
    {
    public:
        SimplifyMesh();
        ~SimplifyMesh();

        static ErrorCode QuadricSimplify(ITriMesh* triMesh, Int targetVertexCount);
    };
}

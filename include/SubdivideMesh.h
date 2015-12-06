#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT SubdivideMesh
    {
    public:
        SubdivideMesh();
        ~SubdivideMesh();

        // Catmull-Clark subdivision
        static ErrorCode CCSubdivideMesh(ITriMesh* triMesh);

        static ErrorCode LoopSubdivideMesh(ITriMesh* triMesh, const std::vector<Real>* vertexFields = NULL, std::vector<Real>* insertedVertexFields = NULL);

        static ErrorCode RefineMesh(ITriMesh* triMesh, Int targetVertexCount, const std::vector<Real>* vertexFields = NULL, std::vector<Real>* insertedVertexFields = NULL);
    };
}

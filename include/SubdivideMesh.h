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

        // vertexFields: it could be color, texture coordinate....
        static ErrorCode LoopSubdivideMesh(ITriMesh* triMesh, const std::vector<Real>* vertexFields = NULL, std::vector<Real>* insertedVertexFields = NULL);

        // vertexFields: it could be color, texture coordinate....
        static ErrorCode RefineMesh(ITriMesh* triMesh, Int targetVertexCount, const std::vector<Real>* vertexFields = NULL, std::vector<Real>* insertedVertexFields = NULL);
    };
}

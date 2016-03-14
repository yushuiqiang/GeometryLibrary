#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT UnfoldMesh
    {
    public:
        UnfoldMesh();
        ~UnfoldMesh();

        // This api is not stable at present, please don't use it
        static ErrorCode AnglePreserving(const ITriMesh* triMesh, std::vector<Real>* texCoords);

        // triMesh should have been splitted into disk like topology
        // triMesh should have face normal
        // fixedVertexIndices should have at least 2 vertices for each connected region, usually set to vertices on boundary
        static ErrorCode ConformalMap(const ITriMesh* triMesh, const std::vector<Int>* fixedVertexIndices,
            const std::vector<Real>* fixedVertexCoords, std::vector<Real>* texCoords);

        // iterationCount should larger than 0, usually set to 10
        static ErrorCode OptimizeIsometric(const ITriMesh* triMesh, std::vector<Real>* texCoords, Int iterationCount, 
            const std::vector<Int>* fixedVertexIndex = NULL);
    };
}

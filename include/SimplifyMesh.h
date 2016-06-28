/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT SimplifyMesh
    {
    public:
        SimplifyMesh();
        ~SimplifyMesh();

        // vertexFields: it could be color, texture coordinate....
        static ErrorCode QuadricSimplify(ITriMesh* triMesh, Int targetVertexCount, bool keepBoundary = true, 
            const std::vector<Real>* vertexFields = NULL, std::vector<Real>* simplifiedVertexFields = NULL);

        // texCoords: texCoord_tri0_vert0, texCoord_tri0_vert1, texCoord_tri0_vert2, texCoord_tri1_vert0, ......
        // simplifiedTexCoord: the same order as texCoords
        // vertexFields: it could be color or something else...
        static ErrorCode SimplifyWithTextureCoords(ITriMesh* triMesh, Int targetVertexCount, 
            const std::vector<Vector3>* texCoords, std::vector<Vector3>* simplifiedTexCoords, 
            const std::vector<Real>* vertexFields = NULL, std::vector<Real>* simplifiedVertexFields = NULL);
    };
}

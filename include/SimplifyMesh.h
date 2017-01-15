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

        // removingVertices: need removing vertex index
        // vertexMap: simplified vertex index map to origin vertex index
        // targetVertexCount: controling simplified vertex count. Usually *targetVertexCount == removingVertices.size()
        // sharpAngle: if edge faces' angle is larger than sharpAngle, the edge will be sharp edge and its vertex position will be fixed. 
        // sharpAngle range (0, 180 * ONE_RADIAN)
        // vertexSharpFlags: vertex flag on sharp edge is 1; sharp edge is defined from sharpAngle
        static ErrorCode SimplifyByRemovingVertex(ITriMesh* triMesh, const std::vector<Int>& removingVertices, 
            std::vector<Int>* vertexMap, const Int* targetVertexCount, const Real* sharpAngle, 
            std::vector<bool>* vertexSharpFlags);
    };
}

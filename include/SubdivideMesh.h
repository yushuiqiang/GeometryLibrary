/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{

    class GPP_EXPORT SubdivideMesh
    {
    public:
        enum RefineMeshType
        {
            REFINE_MESH_SPLIT_EDGE,
            REFINE_MESH_INSERT_CENTROID
        };

        SubdivideMesh();
        ~SubdivideMesh();

        // vertexFields: it could be color, texture coordinate....
        // Normal of result triMesh is not updated here
        static ErrorCode LoopSubdivideMesh(ITriMesh* triMesh, const std::vector<Real>* vertexFields = NULL, std::vector<Real>* insertedVertexFields = NULL);

        // rename the old refime mesh as DensifyMesh
        // vertexFields: it could be color, texture coordinate....
        // Normal of result triMesh is not updated here
        static ErrorCode DensifyMesh(ITriMesh* triMesh, Int targetVertexCount, const std::vector<Real>* vertexFields = NULL, std::vector<Real>* insertedVertexFields = NULL);

        // currently, the two APIs are not stable. Please do not use them now.
        // There are two types of the input parameter:
        // 1. targetVertexCount != NULL and targetDensity == NULL
        // 2. targetVertexCount == NULL and targetDensity != NULL
        // other kind of input parameters are not acceptable.
        // vertexFields: it could be color, texture coordinate....
        static ErrorCode _RefineMesh(ITriMesh* triMesh, const Int *targetVertexCount, const Real *targetDensity = NULL, const std::vector<Real>* vertexFields = NULL, std::vector<Real>* insertedVertexFields = NULL);
        static ErrorCode _RefineMesh(ITriMesh* triMesh, Int targetVertexCount, const std::vector<std::pair<Int, Int> >& forbidFlipVertexPairs);
    };
}

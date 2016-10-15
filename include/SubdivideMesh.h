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

        // internal use only.
        // note: this API will refine the mesh to the targetVertexCount.
        // For some special requirement, there may be some input vertex pair which can not be flipped during the refine process. So pass in such parameters.
        static ErrorCode _RefineMesh(ITriMesh* triMesh, Int targetVertexCount, const std::vector<std::pair<Int, Int> >& forbidFlipVertexPairs);
    };
}

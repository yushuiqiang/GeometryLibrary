/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "TriMesh.h"
#include <vector>

namespace GPP
{
    enum DeformMeshType
    {
        DEFORM_MESH_TYPE_FAST = 0,
        DEFORM_MESH_TYPE_ACCURATE
    };

    class DeformMeshImpl;
    class GPP_EXPORT DeformMesh
    {
    public:
        DeformMesh();
        ~DeformMesh();
        
        // vertexFlags: 0 - free, 1 - fixed
        ErrorCode Init(ITriMesh* triMesh, const std::vector<bool>& vertexFixFlags, bool consolidateGeometry = true);

        // targetVertexIds and targetCoords are 1 - 1 correspondance, and they are used as position constraints in deformation
        // target vertex should be fixed in Init
        ErrorCode Deform(const std::vector<Int>& targetVertexIds, const std::vector<Vector3>& targetCoords, DeformMeshType deformType);

        // maxIteration will reset to 10
        void Clear(void);

        // maxIteration >= 1, its default value is 10
        void SetMaxIteration(Int maxIteration);

        // it is used internel for dump
        void _SetTriMesh(ITriMesh* triMesh);

    private:
        DeformMeshImpl* mpImpl;
        Int mMaxIteration;
    };
}

/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    class DeformMeshImpl;
    class GPP_EXPORT DeformMesh
    {
    public:
        DeformMesh();
        ~DeformMesh();
        
        ErrorCode Init(ITriMesh* triMesh, const std::vector<bool>& vertexFixFlags);

        // targetVertexIds and targetCoords are 1 - 1 correspondance, and they are used as position constraints in deformation
        // vertexFlags: 0 - free, 1 - fixed
        ErrorCode Deform(const std::vector<Int>& targetVertexIds, const std::vector<Vector3>& targetCoords);

        void Clear(void);

    private:
        DeformMeshImpl* mpImpl;
    };
}

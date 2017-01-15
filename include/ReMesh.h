/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT Remesh
    {
    public:
        Remesh();
        ~Remesh();

        static ErrorCode UniformRemesh(ITriMesh* triMesh, Int targetVertexCount, Real sharpAngle, Int optimiseCount = 2,
            const std::vector<Real>* vertexFields = NULL, std::vector<Real>* remeshVertexFields = NULL);

    };
}

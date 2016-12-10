/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT FilterMesh
    {
    public:
        FilterMesh();
        ~FilterMesh();

        // positionWeight: (REAL_TOL, +). Larger value will smooth less
        // Normal of result triMesh is not updated here
        static ErrorCode LaplaceSmooth(ITriMesh* triMesh, bool keepBoundary = true, Real positionWeight = 1.0, 
            const std::vector<Int>* softConstraints = NULL);

        // intensity: (1.0, +). Larger value will enhance more
        // Normal of result triMesh is not updated here
        static ErrorCode EnhanceDetail(ITriMesh* triMesh, Real intensity = 2.0);

    };
}

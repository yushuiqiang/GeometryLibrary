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

        // positionWeight: (0, +). Larger value will smooth less.
        static ErrorCode LaplaceSmooth(ITriMesh* triMesh, bool keepBoundary = true, Real positionWeight = 1.0);

        // intensity: (1.0, +). Larger value will enhance more.
        static ErrorCode EnhanceDetail(ITriMesh* triMesh, Real intensity = 2.0);

        // compressRatio: (0, 1], smaller value will compress more
        static ErrorCode CompressHeightField(std::vector<Real>* heightField, Int resolutionX, Int resolutionY, Real compressRatio);
    };
}

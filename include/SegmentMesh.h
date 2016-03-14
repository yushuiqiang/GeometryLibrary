#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT SegmentMesh
    {
    public:
        SegmentMesh();
        ~SegmentMesh();

        static ErrorCode RegionGrowingFromSeeds(const ITriMesh* triMesh, const std::vector<Int>* seedVertexIds, 
            std::vector<Int>* segmentRes);
    };
}

#pragma once
#include "GppDefines.h"
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT OptimiseCurve
    {
    public:
        OptimiseCurve();
        ~OptimiseCurve();

        // curveList: polyline vertex ids. If first id == last id, then curveList is a close polyline
        // smoothWeight: [0, 1]
        // iterationCount >= 1
        static ErrorCode SmoothCurveOnMesh(ITriMesh* triMesh, const std::vector<Int>& curveList, 
            Real smoothWeight, Int iterationCount);
    };
}

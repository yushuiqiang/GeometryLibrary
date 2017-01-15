#pragma once
#include "GppDefines.h"
#include "TriMesh.h"
#include "Plane3.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT OptimiseCurve
    {
    public:
        OptimiseCurve();
        ~OptimiseCurve();

        // curveList: polyline vertex ids. 
        // smoothWeight: [0, 1]
        // iterationCount >= 1
        static ErrorCode SmoothCurveOnMesh(ITriMesh* triMesh, const std::vector<Int>& curveList, bool isCurveClose, Real sharpAngle,
            Real smoothWeight, Int iterationCount);


        static ErrorCode ApproximateOffsetCurveOnMesh(ITriMesh* triMesh, std::vector<Int>& centerCurve, bool isCurveClose,
            Real diffuseSize, std::vector<Int>& topCurve, std::vector<Int>& downCurve, std::vector<Int>& stringTriangles);


        static ErrorCode MakeCurveBijective(ITriMesh* triMesh, const std::vector<Int>& centerCurve, std::vector<Int>& topCurve, 
            std::vector<Int>& downCurve, bool isCurveClose);


        static ErrorCode SubdividePolyline(std::vector<GPP::Vector3>& pointList, int subdCount, bool isClose);

        
        static ErrorCode ConnectVertexByCuttingPlane(const ITriMesh* triMesh, Int startId, Int endId, const Plane3& cuttingPlane,
            std::vector<PointOnEdge>& pathPointInfos);
    };
}

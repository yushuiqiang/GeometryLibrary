/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "Vector3.h"
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    struct Obb;
    struct PointOnFace;
    class QueryTriangleTool;
    class MeshQueryTree;
    enum QueryMeshToolMethod
    {
        QueryMeshToolType_Normal = 0,   // tree-based method
        QueryMeshToolType_Simple = 1    // brute-force method
    };

    // This class is for querying points to triangles(mesh) distances, or projecting point to triangles(mesh).
    // It is much faster than the brute-force API in class MeasureMesh.
    // USAGE: 1. construct a triangles tool:                  MeshQueryTool tool;
    //        2. initialize the tool with the reference mesh: tool.Init(refMesh);
    //        3. query point/points use the tool:             tool.QueryNearestTriangle(point, ...);
    class GPP_EXPORT MeshQueryTool
    {
    public:
        MeshQueryTool();
        ~MeshQueryTool();

        ErrorCode Init(const ITriMesh* refTriMesh);
        ErrorCode QueryNearestTriangle(const Vector3& queryCoord, PointOnFace* projectPoint, Real* distance = NULL, Vector3* projectCoord = NULL) const;
        ErrorCode QueryNearestTriangles(const std::vector<Vector3>& queryCoords, std::vector<PointOnFace>* projectPoints, std::vector<Real>* distances = NULL, std::vector<Vector3>* projectCoords = NULL) const;

        // It will compute the intersection points with the ray and the triMesh. And it will return the nearest k (=maxIntersectCount) intersections.
        // If there are less intersections than the maxIntersectCount, only the real number of intersection points are returned.
        // NOTE: if there is no intersecting point, the output will be with zero size.
        ErrorCode RayIntersections(const Vector3& rayOrigin, const Vector3& rayDirection, Int maxIntersectCount, std::vector<PointOnFace>* intersectPoints,
            std::vector<Real>* distances = NULL, std::vector<Vector3>* intersectCoords = NULL) const;

        const ITriMesh* GetReferenceMesh() const;

        void SetMaxSearchRadius(Real maxRadius);
    private:
        QueryMeshToolMethod mMethod;
        MeshQueryTree* mpQueryTree;
        const ITriMesh* mpTriMesh;
        Real mMaxSearchRadius;
    };
}

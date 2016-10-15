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

        const ITriMesh* GetReferenceMesh() const;

        // The following functions are internal use only.
        ErrorCode _CollectAllBoundingBox(std::vector<Obb>& boundingBoxes, std::vector<Int>* depths);
        ErrorCode _CollectBoundingBoxNearPoint(const Vector3& point, Real radius, std::vector<Obb>& boundingBoxes, std::vector<Int>* depths, std::vector<Vector3>* relavantVoxelCenters = NULL);

    private:
        QueryMeshToolMethod mMethod;
        MeshQueryTree* mpQueryTree;
        const ITriMesh* mpTriMesh;
    };
}

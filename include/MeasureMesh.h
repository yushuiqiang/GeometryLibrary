/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "TriMesh.h"
#include "ITriangleList.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT IMeshDistance
    {
    public:
        IMeshDistance(){};

        virtual Real GetEdgeLength(Int vertexId0, Int vertexId1) const = 0;
        
        virtual ~IMeshDistance(){};
    };

    class GPP_EXPORT EuclidDistance : public IMeshDistance
    {
    public:
        EuclidDistance(const ITriangleList* triMesh);

        virtual Real GetEdgeLength(Int vertexId0, Int vertexId1) const;

        virtual ~EuclidDistance();

    private:
        const ITriangleList* mTriMesh;
    };

    class GPP_EXPORT PrincipalCurvatureDistance : public IMeshDistance
    {
    public:
        PrincipalCurvatureDistance(const ITriangleList* triMesh, const std::vector<Vector3>* alignDirs,
            const std::vector<Real>* minCurvature, const std::vector<Real>* maxCurvature, Real weight);

        virtual Real GetEdgeLength(Int vertexId0, Int vertexId1) const;

        virtual ~PrincipalCurvatureDistance();

    private:
        const ITriangleList* mTriMesh;
        const std::vector<Vector3>* mAlignDirs;
        const std::vector<Real>* mMinCurvature;
        const std::vector<Real>* mMaxCurvature;
        Real mWeight;
    };

    class GPP_EXPORT MeasureMesh
    {
    public:
        MeasureMesh();
        ~MeasureMesh();

        // note: path will through pass mesh vertex, thus it is an approximate geodesics in mesh
        // sectionVertexIds: line segments vertex ids, like vertexId0, vertexId1, vertexId2 ... ... vertexIdn
        // isSectionClose: whether vertexId0 is connected with vertexIdn
        // pathVertexIds: shortest path between sectionVertexIds
        static ErrorCode ComputeApproximateGeodesics(const ITriMesh* triMesh, const std::vector<Int>& sectionVertexIds, 
            bool isSectionClose, std::vector<Int>& pathVertexIds, Real& distance, const IMeshDistance* meshDistance = NULL);
        // Internal use api
        static ErrorCode _ComputeApproximateGeodesics(const ITriangleList* triangles, const std::vector<Int>& sectionVertexIds, 
            bool isSectionClose, std::vector<Int>& pathVertexIds, Real& distance, const IMeshDistance* meshDistance = NULL);
        
        // note: path will pass through mesh edge, thus it is an accurate geodesics in mesh
        // sectionVertexIds: line segments vertex ids, like vertexId0, vertexId1, vertexId2 ... ... vertexIdn
        // isSectionClose: whether vertexId0 is connected with vertexIdn
        // pathPointPositions: shortest path between sectionVertexIds
        // pathPointInfos: store the information of each path points
        static ErrorCode ComputeExactGeodesics(const ITriMesh* triMesh, const std::vector<Int>& sectionVertexIds, bool isSectionClose, std::vector<Vector3>& pathPointPositions, Real& distance, std::vector<PointOnEdge> *pathPointInfos);
        // Internal use api
        static ErrorCode _ComputeExactGeodesics(const ITriangleList* triangles, const std::vector<Int>& sectionVertexIds, bool isSectionClose, std::vector<Vector3>& pathPointPositions, Real& distance, std::vector<PointOnEdge> *pathPointInfos);

        // This API is a quick version for computing a cross-edge geodesics. But this API will get a slight not-so-exact geodesic path.
        // accuracy: [0, 1]. accuracy of the geodesic result. it is a balance with the accuracy and computation time. 
        // accuracy = 1.0 for exact geodesics but very slow, accuracy = 0 for by-vertex geodesics but not very exact.
        // we suggest to use default value 0.5, it is quick and has about 0.05% deviation with the exact geodesic.
        static ErrorCode FastComputeExactGeodesics(const ITriMesh* triMesh, const std::vector<Int>& sectionVertexIds, bool isSectionClose, 
            std::vector<Vector3>& pathPointPositions, Real& distance, std::vector<PointOnEdge> *pathPointInfos, Real accuracy = 0.5);

        static ErrorCode ComputeArea(const ITriMesh* triMesh, Real& area);

        // Note: User should be aware that this function can ONLY calculte watertight mesh which has no self-intersection. 
        // Otherwise, the result will have deviation.
        static ErrorCode ComputeVolume(const ITriMesh* triMesh, Real& volume);

        // curvature is related to triMesh's size, if triMesh' size *= s, then curvature /= s;
        static ErrorCode ComputeMeanCurvature(const ITriMesh* triMesh, std::vector<Real>& curvature);

        static ErrorCode ComputeGaussCurvature(const ITriMesh* triMesh, std::vector<Real>& curvature);

        static ErrorCode ComputePrincipalCurvature(const ITriMesh* triMesh, std::vector<Real>& minCurvature,
            std::vector<Real>& maxCurvature, std::vector<Vector3>& minDirs, std::vector<Vector3>& maxDirs);

        // If the rays starting from the vertex can not be intersected with the mesh, the thickness value is 0.0 and the isInfiniteValue there is true
        static ErrorCode ComputeThickness(const ITriMesh* triMesh, std::vector<Real>& thickness, std::vector<bool> *isInfiniteValue = NULL);

        // Compute the triangle area
        static Real TriangleArea(const Vector3& triangleV0, const Vector3& triangleV1, const Vector3& triangleV2);

        // Compute distance from point to line segment
        // NOTE: projPoint = lineStartPos * (1.0 - t) + lineEndPos * t
        static ErrorCode PointToLineSegmentDistance(const Vector3& point, 
            const Vector3& lineStartPos, const Vector3& lineEndPos, 
            Real& distance, Vector3* projectCoord = NULL, Real* t = NULL);

        // Compute distance from point to one triangle
        // NOTE: projPoint = V0 * (1.0 - u - v) + V1 * u + V2 * v, (0.0 <= u, v <= 1.0)
        static ErrorCode PointToTriangleDistance(const Vector3& point, 
            const Vector3& triangleV0, const Vector3& triangleV1, const Vector3& triangleV2, 
            Real& distance, Vector3* projectCoord = NULL, Real* projU = NULL, Real* projV = NULL);

        // Compute distance from point to one OBB bounding-box
        static ErrorCode PointToBoundingBoxDistance(const Vector3& point, const Obb& boundingBox, 
            Real& distance, Vector3* projectCoord = NULL, bool *isInside = NULL);

        // Compute the intersection point start from the point rayOrigin along the direction rayDirection.
        // NOTE: intersectCoord = V0 * (1.0 - u - v) + V1 * u + V2 * v;
        // NOTE: if isIntersectInside is false, other output parameter are meaning-less.
        static ErrorCode RayToTriangleIntersect(const Vector3& rayOrigin, const Vector3& rayDirection, 
            const Vector3& triangleV0, const Vector3& triangleV1, const Vector3& triangleV2,
            bool &isIntersected, Real* distance = NULL, Vector3* intersectCoord = NULL, Real* intersectU = NULL, Real* intersectV = NULL);

        // Compute the distance from one point to the mesh. 
        // NOTE: this API calculate the accurate distance but it is slow when calling repeatly.
        // SUGGESTION: if we only calculte one point, we may use this API. 
        //             But if we calculte many points, please use TriangleTools instead for performance issue.
        static ErrorCode BruteforceQueryNearestTriangle(const Vector3& point, const ITriMesh* triMesh, PointOnFace& projectPoint, 
            Real* distance = NULL, Vector3* projectCoord = NULL);
        
        // Internal use only
        static ErrorCode _BruteforceQueryNearestTriangle(const std::vector<Vector3>& points, const ITriMesh* triMesh, 
            std::vector<PointOnFace>& projectPoints, std::vector<Real>* distances = NULL, std::vector<Vector3>* projectCoords = NULL);
    };}

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
    class GPP_EXPORT MeasureMesh
    {
    public:
        MeasureMesh();
        ~MeasureMesh();

        // note: path will through pass mesh vertex, thus it is an approximate geodesics in mesh
        // sectionVertexIds: line segments vertex ids, like vertexId0, vertexId1, vertexId2 ... ... vertexIdn
        // isSectionClose: whether vertexId0 is connected with vertexIdn
        // pathVertexIds: shortest path between sectionVertexIds
        static ErrorCode ComputeApproximateGeodesics(const ITriMesh* triMesh, const std::vector<Int>& sectionVertexIds, bool isSectionClose, std::vector<Int>& pathVertexIds, Real& distance);
        // Internal use api
        static ErrorCode _ComputeApproximateGeodesics(const ITriangleList* triangles, const std::vector<Int>& sectionVertexIds, bool isSectionClose, std::vector<Int>& pathVertexIds, Real& distance);
        
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
    };}

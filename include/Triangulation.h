#pragma once
#include "GppDefines.h"
#include "Vector2.h"
#include "TriMesh.h"

namespace GPP
{
    class ITriMesh;
    class GPP_EXPORT Triangulation
    {
    public:
        Triangulation();
        ~Triangulation();

        static ErrorCode ConstrainedDelaunay2D(const std::vector<Vector2>& inputPointList, 
            const std::vector<std::vector<Int> >* polylineList, 
            const std::vector<std::vector<Int> >* directPolylineList,
            std::vector<Int>& triangleList, std::vector<Int>* noUsePointList);

        // sharpAngle: if edge faces' angle is larger than sharpAngle, the edge will be sharp edge and fixed. sharpAngle range (0, 180 * ONE_RADIAN)
        // polylineList: fixed edges
        // forbiddenEdges: edge_0_v0, edge_0_v1, edge_1_v0, edge_1_v1, ......, edge_n_v0, edge_n_v1. Edge swap operation will not generate forbiddenEdges
        static ErrorCode ConstrainedDelaunayOptimization(ITriMesh* triMesh, Real* sharpAngle,
            const std::vector<std::vector<Int> >* polylineList, const std::vector<Int>* forbiddenEdges);

        // pointsOnFace or pointsOnVertex should not be on vertex
        // Tesselated mesh vertex will be in order: triMesh, pointsOnFace, pointsOnEdge
        // triMesh's normal is not updated
        static ErrorCode MutualTessellation(ITriMesh* triMesh, const std::vector<PointOnFace>* pointsOnFace, 
            const std::vector<PointOnEdge>* pointsOnEdge, std::vector<bool>* pointValidFlags);

        // sharpAngle: if edge faces' angle is larger than sharpAngle, the edge will be sharp edge and its vertex position will be fixed. 
        // sharpAngle range (0, 180 * ONE_RADIAN)
        // vertexFields is both input and output
        // forbiddenEdges: edge_0_v0, edge_0_v1, edge_1_v0, edge_1_v1, ......, edge_n_v0, edge_n_v1. Edge swap operation will not generate forbiddenEdges
        static ErrorCode CentroidVoronoiOptimization(ITriMesh* triMesh, Real* sharpAngle, std::vector<Real>* vertexFields, 
            const std::vector<Int>* forbiddenEdges, const std::vector<Int>* fixVertices, 
            const std::vector<std::vector<Int> >* fixPolylines);
    };
}

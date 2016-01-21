#pragma once
#include "ITriMesh.h"
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
        
        // note: path will pass through mesh edge, thus it is an accurate geodesics in mesh
        // sectionVertexIds: line segments vertex ids, like vertexId0, vertexId1, vertexId2 ... ... vertexIdn
        // isSectionClose: whether vertexId0 is connected with vertexIdn
        // pathVertexPositions: shortest path between sectionVertexIds.
        static ErrorCode ComputeExactGeodesics(const ITriMesh* triMesh, const std::vector<Int>& sectionVertexIds, bool isSectionClose, std::vector<Vector3>& pathVertexPositions, Real& distance);

        static ErrorCode ComputeArea(const ITriMesh* triMesh, Real& area);

        // Note: User should be aware that this function can ONLY calculte watertight mesh which has no self-intersection. 
        // Otherwise, the result will have deviation.
        static ErrorCode ComputeVolume(const ITriMesh* triMesh, Real& volume);
    };
}

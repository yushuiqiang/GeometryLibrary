/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "Vector3.h"
#include <vector>

namespace GPP
{
    class ITriMesh;
    class TriMesh;
    class HalfMesh;

    // returned halfmesh's normal is not updated here
    ////////////////////////////////////////////////////////////////////////////////////// 
    // note, face vertex id order: 
    // triMesh->GetTriangleVertexIds(fid, vertexIds);
    // halfMesh->GetFace(fid)->GetEdge()->GetVertex() == triMesh->GetVertex(vertexIds[0]);
    ////////////////////////////////////////////////////////////////////////////////////// 
    extern GPP_EXPORT HalfMesh* CreateHalfMeshFromITriMesh(const ITriMesh* triMesh);

    // inputMesh should not be null
    // convertedMesh's normal is not updated here
    extern GPP_EXPORT ErrorCode ConvertTriMeshToITriMesh(const TriMesh* inputMesh, ITriMesh* convertedMesh);
    
    // triMesh should not be null
    // halfMesh should UpdateVertexIndex before calling
    // triMesh's normal is not updated here
    ////////////////////////////////////////////////////////////////////////////////////// 
    // note, face vertex id order: 
    // triMesh->GetTriangleVertexIds(fid, vertexIds);
    // halfMesh->GetFace(fid)->GetEdge()->GetVertex() == triMesh->GetVertex(vertexIds[0]);
    ////////////////////////////////////////////////////////////////////////////////////// 
    extern GPP_EXPORT ErrorCode ConvertHalfMeshToITriMesh(const HalfMesh* halfMesh, ITriMesh* triMesh);

    // Deep Copy
    // vertex coord, normal, color; triangle id, normal
    extern GPP_EXPORT TriMesh* CopyTriMesh(const TriMesh* triMesh);

    // Deep Copy
    // vertex coord, normal; triangle id, normal
    extern GPP_EXPORT ErrorCode CopyTriMesh(const ITriMesh* triMesh, ITriMesh* copyMesh);

    // Deep Copy
    // vertex texture coordinates.
    extern GPP_EXPORT ErrorCode CopyTriMeshTextureCoordinates(const TriMesh* srcTriMesh, TriMesh* targetTriMesh);

    // Related triangles will also be deleted
    // triMesh's normal is not updated here
    extern GPP_EXPORT ErrorCode DeleteTriMeshVertices(ITriMesh* triMesh, const std::vector<Int>& deleteIndex);

    // triMesh's normal is not updated here
    // deleteIsolatedVertices: after deleting triangles, there may exist isolated vertices (degree is zero), if true, isolated vertices will be deleted
    extern GPP_EXPORT ErrorCode DeleteTriMeshTriangles(ITriMesh* triMesh, const std::vector<Int>& deleteIndex, bool deleteIsolatedVertices);

    // triMesh's normal is not updated here
    // This api will delete vertices whose degree is zero
    extern GPP_EXPORT ErrorCode DeleteIsolatedVertices(ITriMesh* triMesh);

    extern ErrorCode ConsolidateDegenerateTriangles(const ITriMesh* triMesh, std::vector<Vector3>& vertexCoords);

    extern ErrorCode ComputeTriangleNormal(const ITriMesh* triMesh, std::vector<Vector3>& normalList);

}

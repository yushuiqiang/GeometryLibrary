/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{

    class TopologyMesh : public ITriMesh
    {
    public:
        TopologyMesh(void);
        TopologyMesh(Int vertexCount);
        TopologyMesh(Int vertexCount, const std::vector<Int>& triangles);
        virtual ~TopologyMesh();

        void SetVertexCount(Int vertexCount);  // valid
        virtual Int GetVertexCount(void) const;  // valid
        virtual Int GetTriangleCount(void) const;  // valid

        virtual Vector3 GetVertexCoord(Int vid) const;
        virtual void SetVertexCoord(Int vid, const Vector3& coord);
        virtual Vector3 GetVertexNormal(Int vid) const;
        virtual void SetVertexNormal(Int vid, const Vector3& normal);

        // vertexIds are in a consistent order in all connected triangles
        virtual void GetTriangleVertexIds(Int fid, Int vertexIds[3]) const;  // valid
        // make sure vertexIdx are in a consistent order in its connected triangles
        virtual void SetTriangleVertexIds(Int fid, Int vertexId0, Int vertexId1, Int vertexId2);  // valid
        virtual Vector3 GetTriangleNormal(Int fid) const;
        virtual void SetTriangleNormal(Int fid, const Vector3& normal);
        
        // Return inserted triangle id
        virtual Int InsertTriangle(Int vertexId0, Int vertexId1, Int vertexId2);  // valid
        // Return inserted vertex id
        virtual Int InsertVertex(const Vector3& coord);
        
        // Be careful: if you swap vertex and popback them, then vertex index after the deleted vertices will be changed.
        // If you want to delete some vertices, please use api DeleteTriMeshVertex in ToolMesh.h which is still developping.
        virtual void SwapVertex(Int vertexId0, Int vertexId1); 
        virtual void PopbackVertices(Int popCount);
        virtual void SwapTriangles(Int fid0, Int fid1);  // valid
        virtual void PopbackTriangles(Int popCount);  // valid

        virtual void UpdateNormal(void);
        // Clear all geometry information to initial state
        virtual void Clear(void);  // valid

    private:
        Int mVertexCount;
        std::vector<Int> mTriangles;
    };
}

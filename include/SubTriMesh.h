/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    class TriMesh;
    // there are some cases we need only use part of the input ITriMesh while we do NOT really need to create a new ITriMesh.
    // Here given a class to represent such sub triMesh structure.
    // Please NOTE: if you use the mutators of the SubTriMesh, the binded ITriMesh will also be modified.
    class GPP_EXPORT SubTriMesh : public ITriMesh
    {
    public:
        enum BuildSubTriMeshType
        {
            BUILD_SUBTRIMESH_TYPE_BY_TRIANGLES = 0, // only the triangles with the input ids will be in the SubTriMesh
            BUILD_SUBTRIMESH_TYPE_BY_VERTICES = 1   // triangle vertex ids are all in will be in the SubTriMesh
        };
        // the subTriangleIds are against the input triMesh.
        explicit SubTriMesh(ITriMesh* triMesh, const std::vector<Int>& entityIds, BuildSubTriMeshType type = BUILD_SUBTRIMESH_TYPE_BY_TRIANGLES);
        explicit SubTriMesh(ITriMesh* triMesh, const std::vector<bool>& entityFlags, BuildSubTriMeshType type = BUILD_SUBTRIMESH_TYPE_BY_TRIANGLES);
        ~SubTriMesh();

        // accessors:
        virtual Int GetVertexCount(void) const;
        virtual Int GetTriangleCount(void) const;

        virtual Vector3 GetVertexCoord(Int vid) const;
        virtual Vector3 GetVertexNormal(Int vid) const;
        virtual void GetTriangleVertexIds(Int fid, Int vertexIds[3]) const;
        virtual Vector3 GetTriangleNormal(Int fid) const;

        // mutators:
        virtual void SetVertexCoord(Int vid, const Vector3& coord);
        virtual void SetVertexNormal(Int vid, const Vector3& normal);
        // make sure vertexIdx are in a consistent order in its connected triangles
        virtual void SetTriangleVertexIds(Int fid, Int vertexId0, Int vertexId1, Int vertexId2);
        virtual void SetTriangleNormal(Int fid, const Vector3& normal);
        // Clear all geometry information to initial state, and the function will NOT clear the binded ITriMesh data.
        virtual void Clear(void);

        // The following APIs are not implemented yet. And please do not use them.
        // Return inserted triangle id (against the subTriMesh)
        virtual Int InsertTriangle(Int vertexId0, Int vertexId1, Int vertexId2);
        // Return inserted vertex id (against the subTriMesh)
        virtual Int InsertVertex(const Vector3& coord);
        // Be careful: if you swap vertex and popback them, then vertex index after the deleted vertices will be changed.
        // If you want to delete some vertices, please use api DeleteTriMeshVertex in ToolMesh.h which is still developping.
        virtual void SwapVertex(Int vertexId0, Int vertexId1); 
        virtual void PopbackVertices(Int popCount);
        virtual void SwapTriangles(Int fid0, Int fid1);
        virtual void PopbackTriangles(Int popCount);
        virtual void UpdateNormal(void);


    private:
        // subTriangleIds have no repeated indices
        void BuildSubTriMeshByTriangles(const std::vector<Int>& subTriangleIds);
        // vertexIds have no repeated indices
        void BuildSubTriMeshByVertices(const std::vector<Int>& vertexIds);
        void BuildSubTriMeshByTriangles(const std::vector<bool>& subTriangleFlags);
        void BuildSubTriMeshByVertices(const std::vector<bool>& vertexFlags);

    private:
        ITriMesh* mpTriMesh;
        std::vector<Int> mSubTriangleIds;
        std::vector<Int> mSubVertexIds;
        std::vector<Int> mVertexIdToSubTriMeshMap;
    };
}
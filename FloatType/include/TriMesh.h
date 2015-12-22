#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{

    struct GPP_EXPORT VertexInfo
    {
        VertexInfo();
        VertexInfo(const Vector3& coord);
        VertexInfo(const Vector3& coord, const Vector3& normal);
        Vector3 mCoord;
        Vector3 mNormal;
        Vector3 mTexCoord;
        Vector3 mColor;
    };

    struct GPP_EXPORT TriangleInfo
    {
        TriangleInfo(Int vertexId0, Int vertexId1, Int vertexId2);
        Int mIndex[3];
        Vector3 mNormal;
    };

    enum MeshType
    {
        MT_NORMAL = 0,
        MT_TRIANGLE_SOUP
    };

    class GPP_EXPORT TriMesh : public ITriMesh
    {
    public:
        TriMesh();

        virtual Int GetVertexCount(void) const;
        virtual Int GetTriangleCount(void) const;

        virtual Vector3 GetVertexCoord(Int vid) const;
        virtual void SetVertexCoord(Int vid, const Vector3& coord);
        virtual Vector3 GetVertexNormal(Int vid) const;
        virtual void SetVertexNormal(Int vid, const Vector3& normal);
        virtual void GetTriangleVertexIds(Int fid, Int vertexIds[3]) const;
        virtual void SetTriangleVertexIds(Int fid, Int vertexId0, Int vertexId1, Int vertexId2);
        virtual Vector3 GetTriangleNormal(Int fid);

        // Return inserted triangle id
        virtual Int InsertTriangle(Int vertexId0, Int vertexId1, Int vertexId2);
        // Return inserted vertex id
        virtual Int InsertVertex(const Vector3& coord);   
        // Return inserted vertex id
        Int InsertVertex(const Vector3& coord, const Vector3& normal);

        virtual void SwapVertex(Int vertexId0, Int vertexId1); 
        virtual void PopbackVertices(Int popCount);
        virtual void SwapTriangles(Int fid0, Int fid1);
        virtual void PopbackTriangles(Int popCount);

        virtual void UpdateNormal(void);     
        virtual void Clear(void);

        // This is used in STL mesh structure, since STL format has no topology information.
        // FuseVertex will make vertices as one vertex if their coorindates' distance is small enough
        void FuseVertex(void);

        void SetMeshType(MeshType meshType);
        MeshType GetMeshType(void) const;
        Vector3 GetVertexColor(Int vid) const;
        void SetVertexColor(Int vid, const Vector3& color);
        Vector3 GetVertexTexcoord(Int vid) const;
        void SetVertexTexcoord(Int vid, const Vector3& texcoord);
        
        void UnifyCoords(Real bboxSize);

        virtual ~TriMesh();

    private:
        MeshType mMeshType;
        std::vector<VertexInfo*> mVertexList;
        std::vector<TriangleInfo*> mTriangleList;
    };
}

#pragma once
#include "ITriMesh.h"
#include <vector>
#include <map>

namespace GPP
{
    class Edge3D;
    class GPP_EXPORT Vertex3D
    {
    public:
        Vertex3D();
        Vertex3D(const Vector3& coord);
        Vertex3D(const Vector3& coord, const Vector3& normal);

        Vector3 GetCoord() const;
        void    SetCoord(const Vector3& coord);
        Vector3 GetNormal() const;
        void    SetNormal(const Vector3& normal);
        Vector3 GetTexcoord() const;
        void    SetTexcoord(const Vector3& texCoord);
        Vector3 GetColor() const;
        void    SetColor(const Vector3& color);
        Edge3D* GetEdge();
        const Edge3D* GetEdge() const;
        void    SetEdge(Edge3D* edge);
        Int     GetId() const;
        void    SetId(Int id);
        Int     GetDegree(void) const;

        ~Vertex3D();

    private:
        Vector3 mCoord;
        Vector3 mNormal;
        Vector3 mTexCoord;
        Vector3 mColor;
        Edge3D* mpEdge;
        Int     mId;
    };

    class Face3D;
    class GPP_EXPORT Edge3D
    {
    public:
        Edge3D();

        Vertex3D* GetVertex();
        const Vertex3D* GetVertex() const;
        void      SetVertex(Vertex3D* vertex);
        Edge3D*   GetPair();
        const Edge3D* GetPair() const;
        void      SetPair(Edge3D* edge);
        Edge3D*   GetNext();
        const Edge3D* GetNext() const;
        void      SetNext(Edge3D* edge);
        Edge3D*   GetPre();
        const Edge3D* GetPre() const;
        void      SetPre(Edge3D* edge);
        Face3D*   GetFace();
        const Face3D* GetFace() const;
        void      SetFace(Face3D* face);
        Int       GetId() const;
        void      SetId(Int id);

        ~Edge3D();

    private:
        Vertex3D* mpVertex;
        Edge3D*   mpPair;
        Edge3D*   mpNext;
        Edge3D*   mpPre;
        Face3D*   mpFace;
        Int       mId;
    };

    class GPP_EXPORT Face3D
    {
    public:
        Face3D();

        Edge3D* GetEdge();
        const Edge3D* GetEdge() const;
        void    SetEdge(Edge3D* edge);
        Vector3 GetNormal() const;
        void    SetNormal(const Vector3& normal);
        Int     GetId() const;
        void    SetId(Int id);

        ~Face3D();

    private:
        Edge3D* mpEdge;
        Vector3 mNormal;
        Int     mId;
    };

    struct GPP_EXPORT TriangleVertexIndex
    {
        Int mIndex[3];
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

        virtual Int GetVertexCount() const;
        virtual Vector3 GetVertexCoord(Int vid) const;
        virtual void SetVertexCoord(Int vid, const Vector3& coord);
        virtual Vector3 GetVertexNormal(Int vid) const;
        virtual void SetVertexNormal(Int vid, const Vector3& normal);
        virtual Int GetTriangleCount() const;
        virtual void GetTriangleVertexIds(Int fid, Int vertexIds[3]) const;
        virtual void SetTriangleVertexIds(Int fid, Int vertexId0, Int vertexId1, Int vertexId2);
        virtual void UpdateNormal(void);
        virtual Int InsertTriangle(Int vertexId0, Int vertexId1, Int vertexId2);
        virtual Int InsertVertex(const Vector3& coord);
        void InsertVertex(Vertex3D* vertex);     
        Int InsertVertex(const Vector3& coord, const Vector3& normal);
        virtual void Clear(void);

        void DeleteTriangles(const std::vector<int>& deleteTriangleIndex);
        void FuseVertex(void);

        void SetMeshType(MeshType meshType);
        MeshType GetMeshType(void) const;
        Vector3 GetVertexColor(Int vid) const;
        void SetVertexColor(Int vid, const Vector3& color);
        Vector3 GetVertexTexcoord(Int vid) const;
        void SetVertexTexcoord(Int vid, const Vector3& texcoord);
        Vertex3D* GetVertex(Int vid);
        const Vertex3D* GetVertex(Int vid) const; 
        void SetVertex(Int vid, Vertex3D* vertex);
        
        void UnifyCoords(Real bboxSize);

        virtual ~TriMesh();

    private:
        MeshType mMeshType;
        std::vector<Vertex3D*> mVertexList;
        std::vector<TriangleVertexIndex> mTriangleList;
    };

    class GPP_EXPORT HalfMesh
    {
    public:
        HalfMesh();
        
        Vertex3D* GetVertex(Int vid);
        const Vertex3D* GetVertex(Int vid) const;
        void SetVertex(Int vid, Vertex3D* vertex);
        Edge3D* GetEdge(Int eid);
        const Edge3D* GetEdge(Int eid) const;
        Face3D* GetFace(Int fid);
        const Face3D* GetFace(Int fid) const;
        Int GetVertexCount() const;
        Int GetEdgeCount() const;
        Int GetFaceCount() const;

        void InsertVertex(Vertex3D* vertex);
        Vertex3D* InsertVertex(const Vector3& coord);
        Edge3D*   InsertEdge(Vertex3D* vertexStart, Vertex3D* vertexEnd);
        Face3D*   InsertFace(const std::vector<Vertex3D* >& vertexList);

        void UnifyCoords(Real bboxSize);
        void UpdateNormal();
        void ValidateTopology();
        void RemoveEdgeFromEdgeMap(Edge3D* edge);
        void UpdateVertexIndex();
        void UpdateEdgeIndex();
        void UpdateFaceIndex();

        Int ContractInnerEdge(Int edgeId, bool updateEdgeMap);

        ~HalfMesh();

    private:
        std::vector<Vertex3D* > mVertexList;
        std::vector<Edge3D* >   mEdgeList;
        std::vector<Face3D* >   mFaceList;
        std::map<std::pair<Vertex3D*, Vertex3D*>, Edge3D* > mEdgeMap; //Only used in construct mesh
    };
}

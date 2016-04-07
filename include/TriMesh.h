/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "ITriMesh.h"
#include <vector>
#include <map>

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
        Vector3 mTexCoord[3];
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
        virtual Vector3 GetTriangleNormal(Int fid) const;
        virtual void SetTriangleNormal(Int fid, const Vector3& normal);

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
        ErrorCode FuseVertex(void);

        void SetMeshType(MeshType meshType);
        MeshType GetMeshType(void) const;
        Vector3 GetVertexColor(Int vid) const;
        void SetVertexColor(Int vid, const Vector3& color);
        Vector3 GetVertexTexcoord(Int vid) const;
        void SetVertexTexcoord(Int vid, const Vector3& texcoord);
        Vector3 GetTriangleTexcoord(Int fid, Int localVid) const;
        void SetTriangleTexcoord(Int fid, Int localVid, const Vector3& texcoord);
        
        void UnifyCoords(Real bboxSize, Real* scaleValue = NULL, Vector3* objCenterCoord = NULL);
        void UnifyCoords(Real scaleValue, const Vector3& objCenterCoord);

        virtual ~TriMesh();

    private:
        MeshType mMeshType;
        std::vector<VertexInfo*> mVertexList;
        std::vector<TriangleInfo*> mTriangleList;
    };

    // mVertexId[0] < mVertexId[1]
    // In manifold sturcture: 1. Edge on boundary: mFaceIds.size() == 1; 2. Other: mFaceIds.size() == 2
    struct EdgeInfo
    {
        EdgeInfo();
        EdgeInfo(Int vertexId0, Int vertexId1);
        void SetVertexIds(Int vertexId0, Int vertexId1);

        Int mVertexId[2];
        std::vector<Int> mFaceIds;
    };

    extern ErrorCode ConstructEdgeInfo(const ITriMesh* triMesh, std::vector<EdgeInfo>& edgeInfoList, 
        std::vector<std::map<Int, Int> >* vertexEdgeMap = NULL);

    // store the point on edge informations:
    // if the point is exactly on the mesh vertex, the vertex id is stored in mVertexIdStart, and mVertexIdEnd is -1.
    // if the point is on a mesh edge, the two Ints store the two vertex ids for the edge, and the weight indicate the proportion
    // of the point: Point = startVertexPos * mWeight + endVertexPos * (1 - mWeight)
    struct PointOnEdge
    {
        Int  mVertexIdStart;
        Int  mVertexIdEnd;
        Real mWeight;
    };
}

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
        // In the default constructor, TriMesh has no color, vertex texture coordinate, triangle texture coordinate information
        // User can set the information in the constructor or use SetHas** api to allocate the memory
        TriMesh();
        TriMesh(bool hasVertexColor, bool hasVertexTexCoord, bool hasTriangleTexCoord);

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

        // Set** api will allocate memory for the correspondant information
        void SetHasVertexColor(bool has);
        bool HasVertexColor(void) const;
        void SetHasVertexTexCoord(bool has);
        bool HasVertexTexCoord(void) const;
        void SetHasTriangleColor(bool has);
        bool HasTriangleColor(void) const;
        void SetHasTriangleTexCoord(bool has);
        bool HasTriangleTexCoord(void) const;

        // This is used in STL mesh structure, since STL format has no topology information.
        // FuseVertex will make vertices as one vertex if their coorindates' distance is small enough
        ErrorCode FuseVertex(void);

        void SetMeshType(MeshType meshType);
        MeshType GetMeshType(void) const;

        Vector3 GetVertexColor(Int vid) const;
        void SetVertexColor(Int vid, const Vector3& color);
        Vector3 GetVertexTexcoord(Int vid) const;
        void SetVertexTexcoord(Int vid, const Vector3& texcoord);
        Vector3 GetTriangleColor(Int fid, Int localVid) const;
        void SetTriangleColor(Int fid, Int localVid, const Vector3& color);
        Vector3 GetTriangleTexcoord(Int fid, Int localVid) const;
        void SetTriangleTexcoord(Int fid, Int localVid, const Vector3& texcoord);
        
        void UnifyCoords(Real bboxSize, Real* scaleValue = NULL, Vector3* objCenterCoord = NULL);
        void UnifyCoords(Real scaleValue, const Vector3& objCenterCoord);

        void SetDefaultColor(Vector3 color);

        virtual ~TriMesh();

    private:
        MeshType mMeshType;
        std::vector<VertexInfo*> mVertexList;
        std::vector<TriangleInfo*> mTriangleList;
        std::vector<Vector3> mVertexColorList;
        std::vector<Vector3> mVertexTexCoordList;
        std::vector<Vector3> mTriangleColorList;
        std::vector<Vector3> mTriangleTexCoordList;
        bool mHasVertexColor;
        bool mHasVertexTexCoord;
        bool mHasTriangleColor;
        bool mHasTriangleTexCoord;
        Vector3 mDefaultColor;
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

    // oneWayMap: if true, every edge will be in vertexEdgeMap only once like vertexEdgeMap[smallVertexId][largeVertexId]
    extern ErrorCode ConstructEdgeInfo(const ITriMesh* triMesh, std::vector<EdgeInfo>& edgeInfoList, 
        std::vector<std::map<Int, Int> >* vertexEdgeMap = NULL, bool oneWayMap = true);

    extern ErrorCode InsertVertexOnEdge(ITriMesh* triMesh, std::vector<EdgeInfo>& edgeInfoList, 
        std::vector<std::map<Int, Int> >& vertexEdgeMap, bool oneWayMap, Int startVertexId, Int endVertexId, 
        const Vector3& insertCoord, Int* insertVertexId);

    extern ErrorCode ConstructVertexNeighborInfo(const ITriMesh* triMesh, const std::vector<Int>& vertices, 
        std::vector<EdgeInfo>& edgeInfoList);

    // store the point on edge informations:
    // if the point is exactly on the mesh vertex, the vertex id is stored in mVertexIdStart, and mVertexIdEnd is -1.
    // if the point is on a mesh edge, the two Ints store the two vertex ids for the edge, and the weight indicate the proportion
    // of the point: Point = startVertexPos * mWeight + endVertexPos * (1 - mWeight)
    struct GPP_EXPORT PointOnEdge
    {
        PointOnEdge();
        PointOnEdge(Int vertexIdStart, Int vertexIdEnd, Real weight);

        Int  mVertexIdStart;
        Int  mVertexIdEnd;
        Real mWeight;
    };

    // mCoord: barycentric coordinate
    struct GPP_EXPORT PointOnFace
    {
        PointOnFace();
        PointOnFace(Int faceId, const Vector3& coord);

        Int mFaceId;
        Vector3 mCoord;
    };

    struct GPP_EXPORT Obb
    {
    public:
        Vector3 mCenter;     // the center position of the bounding box
        Vector3 mAxis[3];    // the orietation directions. Here, assume the three axes are perpendicular to each other
        Real mExtents[3];    // the 3 1/2-scales on the oritation direction

    public:
        Obb();
        Obb(const Vector3& center, const Vector3 axis[3], const Real extents[3]);

        void Get8CornerPoints(std::vector<Vector3>& cornerPoints) const;
        bool IsPointInside(const Vector3& point) const;
    };
}

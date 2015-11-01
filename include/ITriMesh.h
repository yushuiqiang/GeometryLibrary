#pragma once
#include "Vector3.h"

namespace GPP
{
    class GPP_EXPORT ITriMesh
    {
    public:
        ITriMesh(){}

        virtual Int GetVertexCount() const = 0;
        virtual Vector3 GetVertexCoord(Int pid) const = 0;
        virtual void SetVertexCoord(Int pid, const Vector3& coord) = 0;
        virtual Vector3 GetVertexNormal(Int pid) const = 0;
        virtual void SetVertexNormal(Int, const Vector3& normal) = 0;
        virtual Int GetTriangleCount() const = 0;
        virtual void GetTriangleVertexIds(Int fid, Int vertexIds[3]) const = 0;
        virtual void SetTriangleVertexIds(Int fid, Int vertexId0, Int vertexId1, Int vertexId2) = 0;
        virtual Int InsertTriangle(Int vertexId0, Int vertexId1, Int vertexId2) = 0;
        virtual Int InsertVertex(const Vector3& coord) = 0;
        virtual void UpdateNormal(void) = 0;
        virtual void Clear(void) = 0;

        virtual ~ITriMesh(){};
    };
}

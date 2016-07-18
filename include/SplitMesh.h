/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "TriMesh.h"
#include "Plane3.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT SplitMesh
    {
    public:
        SplitMesh();
        ~SplitMesh();

        // splitted triMesh's normal is not updated here
        // splitLines.at(lineid) is a line vertex list
        static ErrorCode SplitByLines(ITriMesh* triMesh, const std::vector<std::vector<Int> >& splitLines);

        // splitLine should be a simple line: no intersection
        // The first and last points of snipLines should be on vertex
        // triMesh'r normal is not updated
        static ErrorCode InsertSplitLineOnTriMesh(ITriMesh* triMesh, const std::vector<PointOnEdge>& splitLine, 
            std::vector<Int>* newSplitLineIds = NULL);

        // triMesh: new triangles will be added near the cutting plane, since plane will cut triangle into sub-triangles
        // triangleFlags: 1 - above plane, 0 - under plane
        static ErrorCode SplitByPlane(ITriMesh* triMesh, const Plane3* plane, std::vector<bool>* triangleFlags);
    };
}

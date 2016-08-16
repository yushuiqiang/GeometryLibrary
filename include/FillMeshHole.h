/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    enum FillMeshHoleType
    {
        FILL_MESH_HOLE_FLAT = 0,
        FILL_MESH_HOLE_TANGENT,
        FILL_MESH_HOLE_CURVATURE,
        FILL_MESH_HOLE_TRIANGULATION
    };

    class GPP_EXPORT FillMeshHole
    {
    public:
        // Given an input triMesh, it will find out all the hole loops. 
        // Each found hole loop is an array of the hole's boundary vertices IDs. And holesIds outputs all the loops. 
        // holdsIds are all oriented.
        static ErrorCode FindHoles(const ITriMesh* triMesh, std::vector<std::vector<Int> > *holesIds);
        
        // Given an input triMesh, the function will fill the holes and also fill the corresponding vertex fields if required.
        // The input boundarySeedIds parameter are some of the boundary vertices ids in the triMesh, 
        // and it will fill holes that at least one of its boundary vertices are in the seeds. 
        // NOTE: If the boundarySeedIds are empty or NULL, all the holes will be filled.
        static ErrorCode FillHoles(ITriMesh* triMesh, const std::vector<Int>* boundarySeedIds = NULL, FillMeshHoleType method = FILL_MESH_HOLE_FLAT,
            const std::vector<Real>* vertexFields = NULL, std::vector<Real>* insertedVertexFields = NULL);

        // The method will generate a bridge region between the input two edges. And it will generate some new vertices along the bridge region.
        // Now, the input edge pairs can be from the same boundary loop or from different boundary loops.
        // The link rules of each of the pair of vertices are determined by the orientation of the edges.
        // Parameters: 
        //             edge1VertexIds[2], edge2VertexIds[2](in): the vertices ids for the two edges.
        //             vertexFields(in):          could be color or something else.
        //             insertedVertexFields(out): only output the fields of the new generated vertex.
        static ErrorCode BridgeEdges(ITriMesh* triMesh, const Int edge1VertexIds[2], const Int edge2VertexIds[2],
            const std::vector<Real>* vertexFields = NULL, std::vector<Real>* insertedVertexFields = NULL);

    };
}
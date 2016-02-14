#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    enum FillMeshHoleType
    {
        FILL_MESH_HOLE_FLAT = 0,
        FILL_MESH_HOLE_SMOOTH
    };

    class GPP_EXPORT FillMeshHole
    {
    public:
        // Given an input triMesh, it will find out all the hole loops. 
        // Each found hole loop is an array of the hole's boundary vertices IDs. And holesIds outputs all the loops. 
        static ErrorCode FindHoles(const ITriMesh* triMesh, std::vector<std::vector<Int> > *holesIds);
        
        // Given an input triMesh, the function will fill the holes and also fill the corresponding vertex fields if required.
        // The input boundarySeedIds parameter are some of the boundary vertices ids in the triMesh, 
        // and it will fill holes that at least one of its boundary vertices are in the seeds. 
        // NOTE: If the boundarySeedIds are empty or NULL, all the holes will be filled.
        static ErrorCode FillHoles(ITriMesh* triMesh, const std::vector<Int>* boundarySeedIds = NULL, FillMeshHoleType method = FILL_MESH_HOLE_FLAT,
            const std::vector<Real>* vertexFields = NULL, std::vector<Real>* insertedVertexFields = NULL);
    };
}
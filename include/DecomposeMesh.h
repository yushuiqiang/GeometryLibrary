#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT DecomposeMesh
    {
    public:
        DecomposeMesh();
        ~DecomposeMesh();

        static Int DecomposeHeightField(ITriMesh* triMesh, std::vector<Real>* heightField, std::vector<Vector3>* baseMeshCoords, std::vector<Vector3>* baseMeshNormals);
    };
}

#pragma once
#include "GppDefines.h"
#include <vector>

namespace GPP
{
    class IPointCloud;
    class ITriMesh;
    class GPP_EXPORT ReconstructMesh
    {
    public:
        ReconstructMesh();
        ~ReconstructMesh();

        // ponitCloud should have normals
        // reconstructedMesh should be allocated memory first
        // quality range [0, 6], larger value will more accurate mesh, but speed will be slower.
        // maxHoleAreaRatio: range[0, 1]. If HoleArea / MeshArea > maxHoleAreaRatio, the hole will not be filled
        static ErrorCode Reconstruct(const IPointCloud* pointCloud, ITriMesh* recontructedMesh, 
            Int quality = 5, bool needFillHole = false, const std::vector<Real>* pointFields = NULL, 
            std::vector<Real>* vertexField = NULL, Real maxHoleAreaRatio = 1);
    };
}

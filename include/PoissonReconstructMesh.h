#pragma once
#include "GppDefines.h"
#include <vector>

namespace GPP
{
    enum ReconstructQuality
    {
        RECONSTRUCT_QUALITY_LOW = 0,
        RECONSTRUCT_QUALITY_MEDIUM,
        RECONSTRUCT_QUALITY_HIGH
    };

    class IPointCloud;
    class ITriMesh;
    class GPP_EXPORT PoissonReconstructMesh
    {
    public:
        PoissonReconstructMesh();
        ~PoissonReconstructMesh();

        static ErrorCode Reconstruct(const IPointCloud* pointCloud, ITriMesh* recontructedMesh, ReconstructQuality quality = RECONSTRUCT_QUALITY_MEDIUM, const std::vector<Real>* pointFields = NULL, std::vector<Real>* vertexField = NULL);
    };
}

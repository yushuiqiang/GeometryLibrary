#pragma once
#include "GppDefines.h"
#include <vector>

namespace GPP
{
    enum ReconstructQuality
    {
        RQ_LOW = 0,
        RQ_MEDIUM,
        RQ_HIGH
    };

    class IPointCloud;
    class ITriMesh;
    class GPP_EXPORT PoissonReconstructMesh
    {
    public:
        PoissonReconstructMesh();
        ~PoissonReconstructMesh();

        static ErrorCode Reconstruct(const IPointCloud* pointCloud, ITriMesh* recontructedMesh, ReconstructQuality quality = RQ_MEDIUM, const std::vector<Real>* pointFields = NULL, std::vector<Real>* vertexField = NULL);
    };
}

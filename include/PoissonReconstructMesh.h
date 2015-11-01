#pragma once
#include "GppDefines.h"

namespace GPP
{
    class IPointCloud;
    class ITriMesh;
    class GPP_EXPORT PoissonReconstructMesh
    {
    public:
        PoissonReconstructMesh();
        ~PoissonReconstructMesh();

        static Int Reconstruct(const IPointCloud* pointCloud, ITriMesh* recontructedMesh);
    };
}

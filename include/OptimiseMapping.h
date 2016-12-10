#pragma once
#include "GppDefines.h"
#include "ITriMesh.h"
#include "IPointCloud.h"
#include "TextureImage.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT OptimiseMapping
    {
    public:
        OptimiseMapping();
        ~OptimiseMapping();

        // pointCloudIds should all be valid: imageIndex >= 0
        static ErrorCode TransferMappingToMesh(const IPointCloud* pointCloud, const std::vector<ImageColorId>& pointColorIds,
            ITriMesh* triMesh, std::vector<ImageColorId>& meshColorIds, Real densityScale = 1.0, bool smoothGeometry = false);

        // vertex on boundary should have valid imageColorId: imageIndex >= 0
        static ErrorCode InterpolateImageColorIdsOnMesh(const ITriMesh* triMesh, const std::vector<Int>& validFlags, 
            std::vector<ImageColorId>& imageColorIds);

        // imageColorIds should all be valid: imageIndex >= 0
        static ErrorCode OptimiseIsolateImageColorIdsOnMesh(const ITriMesh* triMesh, std::vector<ImageColorId>& imageColorIds,
            Real isolateValue);

    };
}

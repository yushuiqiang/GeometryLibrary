#pragma once
#include "GppDefines.h"
#include "ITriMesh.h"
#include "TextureImage.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT OptimiseMapping
    {
    public:
        OptimiseMapping();
        ~OptimiseMapping();

        static ErrorCode OptimiseImageColorIdOnMesh(const ITriMesh* triMesh, const std::vector<Int>& fixFlags, 
            std::vector<ImageColorId>& imageColorIds);
    };
}

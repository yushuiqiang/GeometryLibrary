/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "IPointCloud.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT IntrinsicColor
    {
    public:
        IntrinsicColor();
        ~IntrinsicColor();

        // Point cloud should have normal
        static ErrorCode DecomposePointCloudColor(const std::vector<IPointCloud*>& pointCloudList, 
            const std::vector<Real>& colorList, std::vector<Real>& albedoList, std::vector<Real>& shadingList);

    };
}

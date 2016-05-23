/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "GPP.h"
#include "TriMesh.h"

namespace GPP
{
    class GPP_EXPORT TextureImage
    {
    public:
        static ErrorCode CreateTextureImage(const std::vector<Real>& texCoordinates, const std::vector<Vector3>& texColors,
            const std::vector<Int>& faceTextureIds, Int imageWidth, Int imageHeight, std::vector<Vector3>& imageData);
    };
}
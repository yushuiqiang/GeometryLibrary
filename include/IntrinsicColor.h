/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "IPointCloud.h"
#include "PointCloud.h"
#include "Matrix4x4.h"
#include <vector>

namespace GPP
{
    enum PixelType
    {
        PIXEL_TYPE_BACKGROUND = 0,
        PIXEL_TYPE_EXTEND,
        PIXEL_TYPE_VERTEX_COLOR,
        PIXEL_TYPE_IMAGE_COLOR
    };

    class GPP_EXPORT IntrinsicColor
    {
    public:
        IntrinsicColor();
        ~IntrinsicColor();

        // Point cloud should have been aligned before calling this api
        // color value should be in range [0, 1]
        static ErrorCode TuneColorFromSingleLight(const std::vector<IPointCloud*>& pointCloudList, 
            std::vector<std::vector<Vector3> >& colorList);

        
        static ErrorCode TuneTextureImageByVertexColor(const std::vector<Real>& textureCoords, const std::vector<Vector3>& vertexColors, 
            Int imageWidth, Int imageHeight, const std::vector<PixelType> pixelTypes, std::vector<Vector3>& textureColors);

    };
}

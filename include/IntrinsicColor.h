/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "IPointCloud.h"
#include "ITriMesh.h"
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

        // neighborCount: range >= 4, usually be 12, larger value will make color fusing more
        // pointColors: range[0, 1]
        static ErrorCode TuneColorFromMultiFrame(const IPointCloud* pointCloud, Int neighborCount, 
            const std::vector<Int>& colorIds, std::vector<Vector3>& pointColors);

        // Point cloud should have been aligned before calling this api
        // color value should be in range [0, 1]
        // pointDensity: if it is NULL, it will be calculated automatically. If pointClouds are not uniformed, please set it manually
        static ErrorCode TuneColorFromSingleLight(const std::vector<IPointCloud*>& pointCloudList, 
            std::vector<std::vector<Vector3> >& colorList, bool needBlend, const Real* pointDensity,
            const std::vector<std::vector<Int> >* originColorIdList, std::vector<std::vector<Int> >* tunedColorIdList);


        static ErrorCode TuneTextureImageByVertexColor(const std::vector<Real>& textureCoords, const std::vector<Vector3>& vertexColors, 
            Int imageWidth, Int imageHeight, const std::vector<PixelType> pixelTypes, std::vector<Vector3>& textureColors);


        static ErrorCode TuneMeshColorFromMultiPatch(const ITriMesh* triMesh, const std::vector<Int>& colorIds, 
            std::vector<Vector3>& vertexColors);
    };
}

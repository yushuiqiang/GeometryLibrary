/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "IPointCloud.h"
#include "ITriMesh.h"
#include "Matrix4x4.h"
#include "Color4.h"
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

        // rgb range [0, 1]
        // hsv range: h-[0, 360], s-[0, 1], v-[0, 1]
        // H(hue), S(saturation), V(value)
        static Vector3 ConvertRGB2HSV(const Vector3& rgb);

        static Vector3 ConvertHSV2RGB(const Vector3& hsv);

        // Overview: pointColors will be merged into one consistent region by diffusing boundaries of different colorIds
        // pointCloud: it should be uniform. If not, please use TuneMeshColorFromMultiPatch instead
        // neighborCount: range >= 4, usually be 12, larger value will make color fusing more
        // colorIds: points having the same colorId should have consistent color
        // pointColors: range[0, 1], should be in rgb space
        // sharpColorDiff: range[0, 1]. Point color component will be fixed on colorId boundary if color difference between neighbors is larger than sharpColorDiff
        // sharpColorDiff component meaning: 0 - H(hue), 1 - S(saturation), 2 - V(value)
        static ErrorCode TuneColorFromMultiFrame(const IPointCloud* pointCloud, Int neighborCount, 
            const std::vector<Int>& colorIds, std::vector<Vector3>& pointColors, const Vector3& sharpColorDiff = Vector3(0.1, 1.0, 0.5));


        // colorIds: vertices having the same colorId should have consistent color
        // vertexColors: range[0, 1], should be in rgb space
        // sharpColorDiff: range[0, 1]. Point color component will be fixed on colorId boundary if color difference between neighbors is larger than sharpColorDiff
        // sharpColorDiff component meaning: 0 - H(hue), 1 - S(saturation), 2 - V(value)
        static ErrorCode TuneMeshColorFromMultiPatch(const ITriMesh* triMesh, const std::vector<Int>& colorIds, 
            std::vector<Vector3>& vertexColors, const Vector3& sharpColorDiff = Vector3(0.1, 1.0, 0.5));

        
        // Point cloud should have been aligned before calling this api
        // color value should be in range [0, 1]
        // needBlend: colors will be blended near the boundaries of different colorId
        // pointDensity: if it is NULL, it will be calculated automatically. If pointClouds are not uniformed, please set it manually
        // originColorIdList: points having the same colorId should have consistent color. If it is NULL, points from the same cloud will have the same colorId
        // tunedColorIdList: output point colorIds. points having the same colorId should have consistent color
        static ErrorCode TuneColorFromSingleLight(const std::vector<IPointCloud*>& pointCloudList, 
            std::vector<std::vector<Vector3> >& colorList, bool needBlend, const Real* pointDensity,
            const std::vector<std::vector<Int> >* originColorIdList, std::vector<std::vector<Int> >* tunedColorIdList);


        // Overview: texture image color will be tuned into one consistent region by constrained vertex color
        // textureCoords: constrained vertex texture coordinates: coordX_0, coordY_0, coordX_1, coordY_1...... range: [0, 1]
        // vertexColors: constrained vertex colors
        static ErrorCode TuneTextureImageByVertexColor(const std::vector<Real>& textureCoords, const std::vector<Vector3>& vertexColors, 
            Int imageWidth, Int imageHeight, const std::vector<PixelType> pixelTypes, std::vector<Color4>& textureColors);


        // Overview: texture image color will be tuned into one consistent region by constrained vertex color
        // vertexCoords: vertex's coordinates in image space: x0 y0 x1 y1 ......
        // vertexFlags: 1 - color constraints; 0 - not constraints
        // faceVertexIds: a list of the triangle vertex indices. The size of it must be a multiple of three.
        static ErrorCode TuneImageByTriangleColor(const std::vector<Int>& vertexCoords, const std::vector<Vector3>& vertexColors,
            const std::vector<Int>& vertexFlags, const std::vector<Int>& faceVertexIds, 
            Int imageWidth, Int imageHeight, std::vector<Color4>& imageColors);


        // Overview: texture image color will be tuned into one consistent region by constrained point color
        // pointCoords: point's coordinates in image space: x0 y0 x1 y1 ......
        static ErrorCode TuneImageByPointColor(const std::vector<Int>& pointCoords, const std::vector<Vector3>& pointColors,
            Int imageWidth, Int imageHeight, std::vector<Color4>& imageColors);

    };
}

/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "GppDefines.h"
#include "Vector3.h"
#include "Color4.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT ImageColorId
    {
    public:
        ImageColorId();
        ImageColorId(Int imageIndex, Int localX, Int localY);
        void Set(Int imageIndex, Int localX, Int localY);
        void Set(const ImageColorId& colorId);

        Int GetImageIndex()const;
        Int GetLocalX()const;
        Int GetLocalY()const;

    private:
        Int mImageIndex;    // which image the color belongs to
        Int mLocalX;        // the local corresponding image position X, the value should be in [0, imageWidth - 1]
        Int mLocalY;        // the local corresponding image position Y, the value should be in [0, imageHeight - 1]
    };

    class GPP_EXPORT TextureImage
    {
    public:
        enum MatchingType
        {
            MATCHTYPE_SMALL_INDEX_FIRST,
            MATCHTYPE_NEAREST_FIRST
        };

        // This API will generate the texture image for a triangle mesh with colors on triangle vertices. And the colors are rendering onto the image
        // according to their texture cordinates for each triangle-vertices-triple-pair.
        // 
        // Parameters: 
        //   texCoordinates: a list of texture coordinates, they are the collection of the triangle-vertices-texture coordinates
        //                   it stores as {texCoord0_X, texCoord0_Y, texCoord1_X, texCoord1_Y, ...}
        //   faceTextureIds: a list of the triangle texture indices. The size of it must be a multiple of three.
        //                   And for each triple pair, they are indicating the texture coordinates ids of the triangle.
        //                   The real texture coordinate data can be got by the IDs from the texCoordinates
        //   texColors:      a list of texture colors, it has the half size with texCoordinates. And they are corresponding to
        //                   the texCoordinates (texCoord0_X, texCoord0_Y) <--> texColors[0]
        //   outputImageWidth, outputImageHeight, outputImageData: the output image data.
        //   pixelResultInfos: save some auxiliary data for the image. 
        //                     The Int values indicate the result pixel types: 0 -- unfilled pixels, 1 -- expanded pixels, 2 -- filled pixels
        // NOTE: texCoorinates will be trimmed into [0, 1]
        static ErrorCode CreateTextureImageByVertexColors(const std::vector<Real>& texCoordinates, const std::vector<Int>& faceTextureIds,  
            const std::vector<Color4>& texColors,
            Int outputImageWidth, Int outputImageHeight, std::vector<Color4>& outputImageData, std::vector<Int>* pixelResultInfos = NULL);

        // This API will generate texture image for a triangle mesh using the reference images and the vertex to image mappings.
        // Parameters:
        //   texCoordinates: same meaning with CreateTextureImageByVertexColors
        //   faceTextureIds: same meaning with CreateTextureImageByVertexColors
        //   texColorIds:       a list of ImageColorIds for each of the texture coordinate entity. the real color should be found in imageListData.
        //   refImageListData:  a list of the reference image data (row-major matrix)
        //   refImageInfos:     the widths and heights for the reference images. it stores as {image0_width, image0_height, image1_width, image1_height, ...}
        //   outputImageWidth, outputImageHeight, outputImageData: the output image data.
        //   pixelResultInfos:  save some auxiliary data for the image. 
        //                      The Int values indicate the result pixel types: 0 -- unfilled pixels, 1 -- expanded pixels, 
        //                                     2 -- filled pixels by vertex color interpolation, >=3 -- filled pixels by image block replacement
        //                      For pixel with value >=3, (value - 3) is the replace image index at that pixel.
        // NOTE: texCoorinates will be trimmed into [0, 1]
        static ErrorCode CreateTextureImageByRefImages(const std::vector<Real>& texCoordinates, const std::vector<Int>& faceTextureIds,
            const std::vector<ImageColorId>& texColorIds, const std::vector<std::vector<Color4> >& refImageListData, const std::vector<Int>& refImageInfos,
            Int outputImageWidth, Int outputImageHeight, std::vector<Color4>& outputImageData, std::vector<Int>* pixelResultInfos = NULL);

        // This API will expand the image pixels using neighbor colors. Currently, internal use only.
        static ErrorCode _ExpandImagePixels(std::vector<Color4>& imageData, Int imageWidth, Int imageHeight, const std::vector<bool>& isPixelInsideTags);
        
        static bool _IsPointInTriangle(const Real triangleUVs[6], Int x, Int y);

    };
}
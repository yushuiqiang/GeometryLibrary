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
        enum MatchingType
        {
            MATCHTYPE_SMALL_INDEX_FIRST,
            MATCHTYPE_NEAREST_FIRST
        };

        // This API will generate the texture image for a triangle mesh with colors on triangle vertices. And the colors are rendering onto the image
        // according to their texture cordinates for each triangle-vertices-triple-pair.
        // 
        // Paramters: 
        //   texCoordinates: a list of texture coordinates, they are the collection of the triangle-vertices-texture coordinates
        //                   it stores as {texCoord0_X, texCoord0_Y, texCoord1_X, texCoord1_Y, ...}
        //   texColors:      a list of texture colors, it has the half size with texCoordinates. And they are corresponding to
        //                   the texCoordinates (texCoord0_X, texCoord0_Y) <--> texColors[0]
        //   faceTextureIds: a list of the triangle texture indices. The size of it must be a multiple of three.
        //                   And for each triple pair, they are indicating the texture coorindates ids of the triangle.
        //                   The real texture coordinate data can be got by the IDs from the texCoordinates
        //   imageWidth, imageHeight, imageData: the output image data.
        //   alphaData: save some auxiliary data for the image, and now, it saves the filling count for each pixel
        // NOTE: texCoorinates will be trimmed into [0, 1]
        static ErrorCode CreateTextureImage(const std::vector<Real>& texCoordinates, const std::vector<Vector3>& texColors,
            const std::vector<Int>& faceTextureIds, 
            Int imageWidth, Int imageHeight, std::vector<Vector3>& imageData, std::vector<Real>* alphaData = NULL);

        // This API is almost done the same thing with API above, but the colors are not assigned on each triangle vertices. 
        // The colors are found by the accompany reference image, and collected according to the texture coordinates.
        // NOTE: texCoorindates will be trimmed into [0, 1]
        static ErrorCode CreateTextureImage(const std::vector<Real>& texCoordinates, const std::vector<Int>& faceTextureIds, 
            Int refImageWidth, Int refImageHeight, const std::vector<Vector3>& refImage,
            Int imageWidth, Int imageHeight, std::vector<Vector3>& imageData, std::vector<Real>* alphaData = NULL);

        // the following APIs are not stable now, please dont use them
        static ErrorCode _GetTriMeshVertexToPointsMatch(const std::vector<Vector3>& points, const ITriMesh* triMesh, 
            std::vector<Int>& triMeshVertex2pointsMatchIds, std::vector<Real>* matchDistances = NULL, bool isAlsoBasedOnTriMeshVertex = true);
        static ErrorCode _GetTriMeshVertexToPointCloudMatch(const IPointList* pointList, const ITriMesh* triMesh,
            std::vector<Int>& triMeshVertex2PointListMatchIds, std::vector<Real>* matchDistances = NULL, bool isAlsoBasedOnTriMeshVertex = true);

        static ErrorCode _CreateTextureImage(const std::vector<IPointList*>& pointClouds, const ITriMesh* reconstructedMesh,
            const std::vector< std::vector<Int> >& validPointCloudPointIds, const std::vector<Real>& validPointMatchData, 
            const std::vector<Real>& meshVertexTextureCoordinates, const std::vector<Int>& faceTextureIds, 
            const std::vector< std::vector<Vector3> >& imageDatas, const std::vector<Int>& imageInfos,
            MatchingType type, Int imageWidth, Int imageHeight, std::vector<Vector3>& outputImage, std::vector<Real>* alphaData = NULL);
    };
}
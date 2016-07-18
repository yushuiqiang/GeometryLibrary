/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "TriMesh.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT UnfoldMesh
    {
    public:
        UnfoldMesh();
        ~UnfoldMesh();

        // This api is not stable at present, please don't use it
        static ErrorCode AnglePreserving(const ITriMesh* triMesh, std::vector<Real>* texCoords);

        // triMesh: 1. disk like topology; 2. Single connected region
        // fixedVertexIndices should have at least 2 vertices for each connected region, usually set to vertices on boundary
        static ErrorCode ConformalMap(const ITriMesh* triMesh, const std::vector<Int>* fixedVertexIndices,
            const std::vector<Real>* fixedVertexCoords, std::vector<Real>* texCoords);

        // triMesh: 1. disk like topology; 2. Single connected region
        // iterationCount >= 1, usually iterationCount = 10
        static ErrorCode OptimizeIsometric(const ITriMesh* triMesh, std::vector<Real>* texCoords, Int iterationCount, 
            const std::vector<Int>* fixedVertexIndex = NULL);

        // initChartCount: triMesh will be segmented into initChartCount part
        static ErrorCode GenerateUVAtlas(const ITriMesh* triMesh, Int initChartCount, bool needInitSplit, bool needSplitFoldOver,
            std::vector<Real>* texCoords, std::vector<Int>* faceTexIds);

    };
}

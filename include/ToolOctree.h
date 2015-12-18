#pragma once
#include "IPointList.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT Octree
    {
    public:
        // splitCountLeft: max Octree depth
        // nodeList: subset index of pointList, if it is NULL, it will input all points
        // bboxMin, bboxMax: bounding box of the octree. If they are NULL, it will be the bounding box of nodeList
        Octree(Int splitCountLeft, const IPointList* pointList, const std::vector<Int>* nodeList = NULL, const Vector3* bboxMin = NULL, const Vector3* bboxMax = NULL); 
        ~Octree();

        // Split logic: 
        // 1. Not splitted(initial state): no children; mNodeList has indices
        // 2. Splitted: mNodeList will be empty, its nodes are put into children; children will be created
        bool HasSplitted(void);
        // Can not Split if 1) already be splitted or 2) mSplitCountLeft == 0
        bool CanSplit(void);
        void Split(void);
        Int GetChildCount(void);
        Octree* GetChild(Int id);
        const Octree* GetChild(Int id) const;
        Vector3 GetBBoxMin(void) const;
        Vector3 GetBBoxMax(void) const;
        Int GetNodeCount(void) const;
        Int GetNode(Int id) const;
        // Get node index from this octree and its children
        void AppendNodeList(std::vector<Int>& childIndex);
        const IPointList* GetPointList(void) const;

    private:
        Int mSplitCountLeft;
        const IPointList* mPointList;
        Vector3 mBBoxMin;
        Vector3 mBBoxMax;
        std::vector<Int> mNodeList;
        std::vector<Octree*> mChildren;
    };

    ErrorCode GPP_EXPORT FindDistanceNeighbors(const Vector3& searchCoord, Octree* octree, Real distance, Real tol, std::vector<Int>& indexRes);
}

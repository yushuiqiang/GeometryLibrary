#pragma once
#include "IPointList.h"

namespace GPP
{
    class AnnImpl;
    class GPP_EXPORT Ann
    {
    public:
        Ann();
        ~Ann();

        ErrorCode Init(Real* refData, Int refCount, Int refDim);
        // This constructor could eliminate date duplication
        // If you want to use IPointCloud or ITriMesh here, please use PointCloudPointList, TriMeshPointList instead
        ErrorCode Init(const IPointList* pointList);

        // distanceRes: Be careful, it is Square Length!
        // if indexRes or distanceRes is not needed, please set it as NULL
        ErrorCode FindNearestNeighbors(Real* searchData, Int searchCount, Int neighborCount, Int* indexRes, Real* distanceRes);

        // distanceRes: Be careful, it is Square Length!
        // if indexRes or distanceRes is not needed, please set it as NULL
        ErrorCode FindNearestNeighbors(const IPointList* pointList, Int neighborCount, Int* indexRes, Real* distanceRes);

        void Clear(void);

    private:
        AnnImpl* mpImpl;
    };
}

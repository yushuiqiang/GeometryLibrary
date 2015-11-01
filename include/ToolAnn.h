#pragma once
#include "GppDefines.h"

namespace GPP
{
    class AnnImpl;
    class GPP_EXPORT Ann
    {
    public:
        Ann();
        ~Ann();

        Int Init(Real* refData, Int refCount, Int refDim);
        Int FindNearestNeighbors(Real* searchData, Int searchCount, Int neighborCount, Int* indexRes, Real* distanceRes);

    private:
        AnnImpl* mpImpl;
    };
}

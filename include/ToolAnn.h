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

        ErrorCode Init(Real* refData, Int refCount, Int refDim);
        ErrorCode FindNearestNeighbors(Real* searchData, Int searchCount, Int neighborCount, Int* indexRes, Real* distanceRes);

    private:
        AnnImpl* mpImpl;
    };
}

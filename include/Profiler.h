/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "GppDefines.h"

namespace GPP
{
    class GPP_EXPORT Profiler
    {
    public:
        Profiler();
        ~Profiler();

        static Real GetTime(void);
    };
}

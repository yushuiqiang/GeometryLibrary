#pragma once
#include "GppDefines.h"

namespace GPP
{
    class Profiler
    {
    public:
        Profiler();
        ~Profiler();

        static Real GetTime(void);
    };
}

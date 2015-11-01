#pragma once
#include "IPointCloud.h"

namespace GPP
{
    class GPP_EXPORT SamplePointCloud
    {
    public:
        SamplePointCloud();
        ~SamplePointCloud();

        static Int UniformSample(IPointCloud* pointCloud, Int sampleCount, Int* sampleIndex);
    };
}

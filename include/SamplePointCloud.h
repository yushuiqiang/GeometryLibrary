#pragma once
#include "IPointCloud.h"
#include "IPointList.h"

namespace GPP
{
    enum SampleQuality
    {
        SAMPLE_QUALITY_LOW = 0,
        SAMPLE_QUALITY_HIGH
    };

    class GPP_EXPORT SamplePointCloud
    {
    public:
        SamplePointCloud();
        ~SamplePointCloud();

        static ErrorCode UniformSamplePointList(const IPointList* pointList, Int sampleCount, Int* sampleIndex, Int seedId = 0, SampleQuality quality = SAMPLE_QUALITY_HIGH);

        static ErrorCode UniformSample(const IPointCloud* pointCloud, Int sampleCount, Int* sampleIndex, Int seedId = 0, SampleQuality quality = SAMPLE_QUALITY_HIGH);
    };
}

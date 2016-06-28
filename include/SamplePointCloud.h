/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "IPointCloud.h"
#include "IPointList.h"
#include <vector>

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

        // Internal use api
        static ErrorCode _UniformSamplePointList(const IPointList* pointList, Int sampleCount, Int* sampleIndex, 
            Int seedId = 0, SampleQuality quality = SAMPLE_QUALITY_HIGH);

        // sampleIndex should be allocated memory before calling this api
        static ErrorCode UniformSample(const IPointCloud* pointCloud, Int sampleCount, Int* sampleIndex, 
            Int seedId = 0, SampleQuality quality = SAMPLE_QUALITY_HIGH);

        // pointCloud should have normal information
        // uniformWeight: [0, 1]. Larger value will get a more uniform result
        static ErrorCode GeometrySample(const IPointCloud* pointCloud, Int sampleCount, Int* sampleIndex, 
            Real uniformWeight = 0.1, Int neighborCount = 9, Int seedId = 0, SampleQuality quality = SAMPLE_QUALITY_HIGH);

        // Internal use api
        // pointList should have normal information
        static ErrorCode _GeometrySamplePointList(const IPointList* pointList, Int sampleCount, Int* sampleIndex, 
            Real uniformWeight = 0.1, Int neighborCount = 9, Int seedId = 0, SampleQuality quality = SAMPLE_QUALITY_HIGH);
    };
}

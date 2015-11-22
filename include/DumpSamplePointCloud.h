#pragma once
#include "DumpInfo.h"

namespace GPP
{
    extern GPP_EXPORT DumpBase* CreateDumpPointCloudSamplingUniform(void);

    class PointCloud;
    class GPP_EXPORT DumpPointCloudSamplingUniform : public DumpBase
    {
    public:
        DumpPointCloudSamplingUniform();
        ~DumpPointCloudSamplingUniform();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);
        virtual PointCloud* GetPointCloud(Int id = 0);

        void DumpApiInfo(const IPointCloud* pointCloud, Int sampleCount);

    private:
        PointCloud* mpPointCloud;
        Int mSampleCount;
    };
}

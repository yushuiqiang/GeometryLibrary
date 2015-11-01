#pragma once
#include "DumpInfo.h"

namespace GPP
{
    extern DumpBase* CreateDumpPointCloudSamplingUniform(void);

    class PointCloud;
    class DumpPointCloudSamplingUniform : public DumpBase
    {
    public:
        DumpPointCloudSamplingUniform();
        ~DumpPointCloudSamplingUniform();

        virtual void LoadDumpFile(const std::string& fileName);
        virtual Int Run(void);
        virtual PointCloud* GetPointCloud(void);

        void DumpApiInfo(const IPointCloud* pointCloud, Int sampleCount);

    private:
        PointCloud* mpPointCloud;
        Int mSampleCount;
    };
}

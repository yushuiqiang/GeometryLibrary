#pragma once
#include "DumpInfo.h"

namespace GPP
{
    extern DumpBase* CreateDumpPointCloudConsolidationLaplaceSmooth(void);

    class PointCloud;
    class DumpPointCloudConsolidationLaplaceSmooth : public DumpBase
    {
    public:
        DumpPointCloudConsolidationLaplaceSmooth();
        ~DumpPointCloudConsolidationLaplaceSmooth();

        virtual void LoadDumpFile(const std::string& fileName);
        virtual Int Run(void);
        virtual PointCloud* GetPointCloud(void);

        void DumpApiInfo(const IPointCloud* pointCloud, Real percentage, Int times);

    private:
        PointCloud* mpPointCloud;
        Real mPercentage;
        Int mTimes;
    };

    
    extern DumpBase* CreateDumpPointCloudConsolidationNormalCalculation(void);

    class DumpPointCloudConsolidationNormalCalculation : public DumpBase
    {
    public:
        DumpPointCloudConsolidationNormalCalculation();
        ~DumpPointCloudConsolidationNormalCalculation();

        virtual void LoadDumpFile(const std::string& fileName);
        virtual Int Run(void);
        virtual PointCloud* GetPointCloud(void);

        void DumpApiInfo(const IPointCloud* pointCloud, Int quality);

    private:
        PointCloud* mpPointCloud;
        Int mQuality;
    }; 
}

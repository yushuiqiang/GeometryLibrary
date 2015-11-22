#pragma once
#include "DumpInfo.h"

namespace GPP
{
    extern GPP_EXPORT DumpBase* CreateDumpPointCloudConsolidationLaplaceSmooth(void);

    class PointCloud;
    class GPP_EXPORT DumpPointCloudConsolidationLaplaceSmooth : public DumpBase
    {
    public:
        DumpPointCloudConsolidationLaplaceSmooth();
        ~DumpPointCloudConsolidationLaplaceSmooth();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);
        virtual PointCloud* GetPointCloud(Int id = 0);

        void DumpApiInfo(const IPointCloud* pointCloud, Real percentage, Int times);

    private:
        PointCloud* mpPointCloud;
        Real mPercentage;
        Int mTimes;
    };

    
    extern GPP_EXPORT DumpBase* CreateDumpPointCloudConsolidationNormalCalculation(void);

    class GPP_EXPORT DumpPointCloudConsolidationNormalCalculation : public DumpBase
    {
    public:
        DumpPointCloudConsolidationNormalCalculation();
        ~DumpPointCloudConsolidationNormalCalculation();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);
        virtual PointCloud* GetPointCloud(Int id = 0);

        void DumpApiInfo(const IPointCloud* pointCloud, Int quality);

    private:
        PointCloud* mpPointCloud;
        Int mQuality;
    }; 
}

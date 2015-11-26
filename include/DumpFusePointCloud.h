#pragma once
#include "DumpInfo.h"

namespace GPP
{
    extern GPP_EXPORT DumpBase* CreateDumpPointCloudFusionUpdate(void);

    class FusePointCloud;
    class Matrix4x4;
    class IPointCloud;
    class GPP_EXPORT DumpPointCloudFusionUpdate : public DumpBase
    {
    public:
        DumpPointCloudFusionUpdate();
        ~DumpPointCloudFusionUpdate();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);
        virtual PointCloud* GetPointCloud(Int id = 0);

        void DumpApiInfo(const FusePointCloud* fusion, const IPointCloud* pointCloud, const Matrix4x4* transform);

    private:
        FusePointCloud* mpFusion;
        PointCloud* mpPointCloud;
        Matrix4x4* mpTransform;
    };

    extern GPP_EXPORT DumpBase* CreateDumpPointCloudFusionExtract(void);

    class GPP_EXPORT DumpPointCloudFusionExtract : public DumpBase
    {
    public:
        DumpPointCloudFusionExtract();
        ~DumpPointCloudFusionExtract();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);
        virtual PointCloud* GetPointCloud(Int id = 0);

        void DumpApiInfo(const FusePointCloud* fusion);

    private:
        FusePointCloud* mpFusion;
        PointCloud* mpPointCloud;
    };
}

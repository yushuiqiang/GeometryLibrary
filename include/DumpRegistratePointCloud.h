#pragma once
#include "DumpInfo.h"
#include "Vector3.h"
#include "Matrix4x4.h"
#include <vector>

namespace GPP
{
    extern GPP_EXPORT DumpBase* CreateDumpPointCloudRegistrationAlignPointPair(void);

    class PointCloud;
    class GPP_EXPORT DumpPointCloudRegistrationAlignPointPair : public DumpBase
    {
    public:
        DumpPointCloudRegistrationAlignPointPair();
        ~DumpPointCloudRegistrationAlignPointPair();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);

        void DumpApiInfo(const std::vector<Vector3>& pointsRef, const std::vector<Vector3>& pointsFrom, const Matrix4x4* initTransform);
        std::vector<Vector3> GetPointsRef(void) const;
        std::vector<Vector3> GetPointsFrom(void) const;
        const Matrix4x4* GetInitTransform(void) const;

    private:
        std::vector<Vector3> mPointsRef;
        std::vector<Vector3> mPointsFrom;
        Matrix4x4* mpInitTransform;
    };

    
    extern GPP_EXPORT DumpBase* CreateDumpPointCloudRegistrationICP(void);

    class GPP_EXPORT DumpPointCloudRegistrationICP : public DumpBase
    {
    public:
        DumpPointCloudRegistrationICP();
        ~DumpPointCloudRegistrationICP();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);
        virtual PointCloud* GetPointCloud(Int id = 0);

        void DumpApiInfo(const IPointCloud* pointCloudRef, const IPointCloud* pointCloudFrom, const Matrix4x4* initTransform);
        const Matrix4x4* GetInitTransform(void) const;

    private:
        PointCloud* mpPointCloudRef;
        PointCloud* mpPointCloudFrom;
        Matrix4x4* mpInitTransform;
    }; 
}

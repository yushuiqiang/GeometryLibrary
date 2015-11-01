#pragma once
#include "DumpInfo.h"

namespace GPP
{
    extern DumpBase* CreateDumpPointCloudPoissonReconstructMesh(void);

    class IPointCloud;
    class ITriMesh;
    class DumpPointCloudPoissonReconstructMesh : public DumpBase
    {
    public:
        DumpPointCloudPoissonReconstructMesh();
        ~DumpPointCloudPoissonReconstructMesh();

        virtual void LoadDumpFile(const std::string& fileName);
        virtual Int Run(void);
        virtual TriMesh* GetTriMesh(void);
        virtual PointCloud* GetPointCloud(void);

        void DumpApiInfo(const IPointCloud* pointCloud);

    private:
        TriMesh* mpTriMesh;
        PointCloud* mpPointCloud;
    };
}

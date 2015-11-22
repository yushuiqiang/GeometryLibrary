#pragma once
#include "DumpInfo.h"

namespace GPP
{
    extern GPP_EXPORT DumpBase* CreateDumpMeshConsolidationLaplaceSmooth(void);

    class GPP_EXPORT DumpMeshConsolidationLaplaceSmooth : public DumpBase
    {
    public:
        DumpMeshConsolidationLaplaceSmooth();
        ~DumpMeshConsolidationLaplaceSmooth();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);
        virtual TriMesh* GetTriMesh(Int id = 0);

        void DumpApiInfo(const ITriMesh* triMesh, Real percentage, Int times, bool keepBoundary);

    private:
        TriMesh* mpTriMesh;
        Real mPercentage;
        Int mTimes;
        bool mKeepBoundary;
    };

    
    extern GPP_EXPORT DumpBase* CreateDumpMeshConsolidationMakeManifold(void);

    class GPP_EXPORT DumpMeshConsolidationMakeManifold : public DumpBase
    {
    public:
        DumpMeshConsolidationMakeManifold();
        ~DumpMeshConsolidationMakeManifold();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);
        virtual TriMesh* GetTriMesh(Int id = 0);

        void DumpApiInfo(const ITriMesh* triMesh);

    private:
        TriMesh* mpTriMesh;
    }; 


    extern GPP_EXPORT DumpBase* CreateDumpMeshConsolidationGeometry(void);

    class GPP_EXPORT DumpMeshConsolidationGeometry : public DumpBase
    {
    public:
        DumpMeshConsolidationGeometry();
        ~DumpMeshConsolidationGeometry();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);
        virtual TriMesh* GetTriMesh(Int id = 0);

        void DumpApiInfo(const ITriMesh* triMesh, Real minTriangleAngle, Real minEdgeLength, Real foldoverAngleTol);

    private:
        TriMesh* mpTriMesh;
        Real mMinTriangleAngle;
        Real mMinEdgeLength;
        Real mFoldoverAngleTol;
    }; 
}

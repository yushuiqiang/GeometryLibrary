#pragma once
#include "DumpInfo.h"

namespace GPP
{
    extern GPP_EXPORT DumpBase* CreateDumpMeshSubdivisionLoop(void);

    class GPP_EXPORT DumpMeshSubdivisionLoop : public DumpBase
    {
    public:
        DumpMeshSubdivisionLoop();
        ~DumpMeshSubdivisionLoop();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);
        virtual TriMesh* GetTriMesh(Int id = 0);

        void DumpApiInfo(const ITriMesh* triMesh);

    private:
        TriMesh* mpTriMesh;
    };

    
    extern GPP_EXPORT DumpBase* CreateDumpMeshSubdivisionCC(void);

    class GPP_EXPORT DumpMeshSubdivisionCC : public DumpBase
    {
    public:
        DumpMeshSubdivisionCC();
        ~DumpMeshSubdivisionCC();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);
        virtual TriMesh* GetTriMesh(Int id = 0);

        void DumpApiInfo(const ITriMesh* triMesh);

    private:
        TriMesh* mpTriMesh;
    }; 


    extern GPP_EXPORT DumpBase* CreateDumpMeshSubdivisionRefine(void);

    class GPP_EXPORT DumpMeshSubdivisionRefine : public DumpBase
    {
    public:
        DumpMeshSubdivisionRefine();
        ~DumpMeshSubdivisionRefine();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);
        virtual TriMesh* GetTriMesh(Int id = 0);

        void DumpApiInfo(const ITriMesh* triMesh, Int targetVertexCount);

    private:
        TriMesh* mpTriMesh;
        Int mTargetVertexCount;
    }; 
}
